#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "rna_folding.cpp"

// Font data
unsigned char ttf_buffer[1 << 20];
stbtt_bakedchar cdata[96]; // ASCII 32..126 is 95 glyphs

// Load a font using STB TrueType
void initFont() {
    FILE* font_file = fopen("Pixelify_Sans/PixelifySans-VariableFont_wght.ttf", "rb"); // Adjust the font file path as needed
    fread(ttf_buffer, 1, 1 << 20, font_file);
    stbtt_BakeFontBitmap(ttf_buffer, 0, 32.0, ttf_buffer, 1024, 1024, 32, 96, cdata); // font size 32
    fclose(font_file);
}

// Draw text for each RNA node
void drawRNANodes(const std::string& rna_sequence) {
    // Set color for text
    glColor3f(1.0f, 1.0f, 1.0f); // White color

    // Calculate the spacing between text based on the window size and RNA sequence length
    float text_spacing = 2.0f / static_cast<float>(rna_sequence.size() + 1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0);

    for (size_t i = 0; i < rna_sequence.size(); ++i) {
        float x = -1.0f + text_spacing * (i + 1);
        float y = 0.0f;

        char text[2] = {rna_sequence[i], '\0'}; // Convert char to string
        glPushMatrix();
        glTranslatef(x, y, 0);
        glBegin(GL_QUADS);
        for (int j = 0; text[j]; ++j) {
            stbtt_aligned_quad q;
            stbtt_GetBakedQuad(cdata, 1024, 1024, text[j] - 32, &x, &y, &q, 1); // Draw the text
            glTexCoord2f(q.s0, q.t0);
            glVertex2f(q.x0, q.y0);
            glTexCoord2f(q.s1, q.t0);
            glVertex2f(q.x1, q.y0);
            glTexCoord2f(q.s1, q.t1);
            glVertex2f(q.x1, q.y1);
            glTexCoord2f(q.s0, q.t1);
            glVertex2f(q.x0, q.y1);
        }
        glEnd();
        glPopMatrix();
    }

    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_TEXTURE_2D);
}

// Function to draw RNA dots
void drawRNADots(const std::string& rna_sequence) {
    // Set the color for all dots
    glColor3f(1.0f, 0.0f, 0.0f); // Red color

    // Calculate the spacing between dots based on the window size and RNA sequence length
    float dot_spacing = 2.0f / static_cast<float>(rna_sequence.size() + 1);

    // Start drawing the dots
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    for (size_t i = 0; i < rna_sequence.size(); ++i) {
        // Calculate the x-coordinate for the dot
        float x = -1.0f + dot_spacing * (i + 1);
        // Draw the dot at the calculated position
        glVertex2f(x, 0.0f);
    }
    glEnd();
}

// Function to draw RNA bonds
void drawRNABonds(const std::vector<std::pair<int, int>>& traceback, const std::string& rna_sequence) {
    // Set the color for all bonds
    glColor3f(0.0f, 1.0f, 0.0f); // Green color

    // Calculate the spacing between dots based on the window size and RNA sequence length
    float dot_spacing = 2.0f / static_cast<float>(rna_sequence.size() + 1);

    // Start drawing the arcs
    for (const auto& bond : traceback) {
        // Calculate the x-coordinates for the dots
        float x1 = -1.0f + dot_spacing * (bond.first + 1);
        float x2 = -1.0f + dot_spacing * (bond.second + 1);

        // Calculate the center and radius of the arc
        float center_x = (x1 + x2) / 2.0f;
        float radius = std::abs(x1 - x2) / 2.0f;

        // Draw the arc
        glBegin(GL_LINE_STRIP);
        for (float angle = 0.0f; angle <= 3.14159f; angle += 0.01f) {
            float x = center_x + radius * std::cos(angle);
            float y = radius * std::sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
}

int main() {
    std::string rna_sequence = "AAUCCCCCGUGCCCAUAGCGGCGUGGAACCACCCGUUCCCAUUCCGAACACGGAAGUGAAACGCGCCAGCGCCGAUGGUACUGGGCGGGCGACCGCCUGGGAGAGUAGGUCGGUGCGGGGGA";
    std::vector<std::pair<int, int>> fold;
    traceback(create_matrix(rna_sequence, 0), rna_sequence, fold, 0, rna_sequence.size() - 1);
    std::string dot_notation = dot_write(rna_sequence, fold);

    std::cout << rna_sequence << std::endl;
    std::cout << dot_notation << std::endl;

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "RNA Sequence Visualization", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Load font
    initFont();

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

        // Set up the coordinate system
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Draw the RNA dots
        drawRNADots(rna_sequence);

        // Draw the RNA bonds
        drawRNABonds(fold, rna_sequence);

        // Draw the RNA symbols
        drawRNANodes(rna_sequence);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}
