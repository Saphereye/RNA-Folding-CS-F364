#include <GL/freeglut.h>
#include <GLFW/glfw3.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "rna_folding.cpp"

float pan_speed = 0.0f;
float pan_offset = 0.0f;
float zoom_factor = 1.0f;

// Function to render text on the screen
void renderText(float x, float y, const std::string& text) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void drawRNADots(const std::string& rna_sequence) {
    // Calculate the spacing between dots based on the window size and RNA
    // sequence length
    float dot_spacing = 0.1f / zoom_factor;
    float start_x = -1.0f + pan_offset;

    // Arrays to store dot positions and colors
    std::vector<float> dot_positions;
    std::vector<float> dot_colors;

    // Generate dot positions and colors
    for (size_t i = 0; i < rna_sequence.size(); ++i) {
        // Calculate the x-coordinate for the dot
        float x = start_x + dot_spacing * (i + 1);

        // Store dot position
        dot_positions.push_back(x);
        dot_positions.push_back(-0.8f);

        // Set the color based on the nucleotide
        switch (rna_sequence[i]) {
            case 'A':
                dot_colors.push_back(1.0f);  // Red
                dot_colors.push_back(0.0f);
                dot_colors.push_back(0.0f);
                break;
            case 'U':
                dot_colors.push_back(0.0f);  // Green
                dot_colors.push_back(1.0f);
                dot_colors.push_back(0.0f);
                break;
            case 'G':
                dot_colors.push_back(0.0f);  // Blue
                dot_colors.push_back(0.0f);
                dot_colors.push_back(1.0f);
                break;
            case 'C':
                dot_colors.push_back(1.0f);  // Yellow
                dot_colors.push_back(1.0f);
                dot_colors.push_back(0.0f);
                break;
            default:
                dot_colors.push_back(0.5f);  // Gray for wrong nucleotide
                dot_colors.push_back(0.5f);
                dot_colors.push_back(0.5f);
                break;
        }
    }

    // Draw the dots
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, dot_positions.data());
    glColorPointer(3, GL_FLOAT, 0, dot_colors.data());
    glPointSize(10.0f);
    glDrawArrays(GL_POINTS, 0, rna_sequence.size());
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    // Render nucleotide names below the dots
    if (zoom_factor <= 7.0f) {
        for (size_t i = 0; i < rna_sequence.size(); ++i) {
            float x = start_x + dot_spacing * (i + 1);
            std::string nucleotide_name = std::string(1, rna_sequence[i]);
            renderText(x - 0.0075f, -0.9f, nucleotide_name);
        }
    }

    // Debug information: Number of nucleotides
    std::string nucleotide_count =
        "Nucleotides: " + std::to_string(rna_sequence.size());
    renderText(-0.9f, 0.9f, nucleotide_count);
}

void drawRNABonds(const std::vector<std::pair<int, int>>& traceback,
                  const std::string& rna_sequence) {
    // Set the color for all bonds
    glColor3f(1.0f, 1.0f, 1.0f);  // White color bonds

    // Calculate the spacing between dots based on the window size and RNA
    // sequence length
    // float dot_spacing = 2.0f / static_cast<float>(rna_sequence.size() + 1);
    float dot_spacing = 0.1f / zoom_factor;
    float start_x = -1.0f + pan_offset;

    // Start drawing the arcs
    for (const auto& bond : traceback) {
        // Calculate the x-coordinates for the dots
        float x1 = start_x + dot_spacing * (bond.first + 1);
        float x2 = start_x + dot_spacing * (bond.second + 1);

        // Calculate the center and radius of the arc
        float center_x = (x1 + x2) / 2.0f;
        float radius = std::abs(x1 - x2) / 2.0f;

        // Draw the arc
        glBegin(GL_LINE_STRIP);
        for (float angle = 0.0f; angle <= 3.14159f; angle += 0.01f) {
            float x = center_x + radius * std::cos(angle);
            float y = radius * std::sin(angle) - 0.8f;
            glVertex2f(x, y);
        }
        glEnd();
    }

    // Debug information: Number of bonds
    std::string bond_count = "Bonds: " + std::to_string(traceback.size());
    renderText(-0.9f, 0.8f, bond_count);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_LEFT:
                pan_speed = 0.05f;
                break;
            case GLFW_KEY_RIGHT:
                pan_speed = -0.05f;
                break;
            case GLFW_KEY_EQUAL:
                zoom_factor *= 0.9f;
                break;
            case GLFW_KEY_MINUS:
                zoom_factor *= 1.1f;
                break;
            default:
                break;
        }
    } else if (action == GLFW_RELEASE) {
        pan_speed = 0.0f;
    }
}

// The framebuffer size callback function
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);
}

int main(int argv, char** argc) {
    // std::ifstream file("rna/Thermus thermophilus 5S rRNA.rna");

    // std::ifstream file(
    //     "rna/Homo sapiens (human) ABR antisense RNA 1 (ABR-AS1).rna");

    // std::ifstream file("rna/ACA box 91 (SNORA91).rna");

    std::ifstream file(
        "rna/Homo sapiens (human) RNA, U5D small nuclear 1 (RNU5D-1).rna");

    // std::ifstream file("rna/Homo sapiens (human) piR-61154.rna");

    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        return -1;
    }

    // Read the RNA sequence from the file
    std::string rna_sequence;
    std::getline(file, rna_sequence);

    std::vector<std::pair<int, int>> fold;
    traceback(create_matrix(rna_sequence, 0), rna_sequence, fold, 0,
              rna_sequence.size() - 1);

    std::string dot_notation = dot_write(rna_sequence, fold);
    std::cout << rna_sequence << std::endl;
    std::cout << dot_notation << std::endl;

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glutInit(&argv, argc);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(
        800, 600, "RNA Sequence Visualization", glfwGetPrimaryMonitor(), NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    // Set the framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set the keyboard input callback function
    glfwSetKeyCallback(window, key_callback);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Handle panning
        if (pan_speed != 0.0f) {
            pan_offset += pan_speed;
        }

        // Render here
        glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

        // Render the text
        // renderText(-1.0f, -0.95f,
        //            "RNA folding simulation, made in CPP and OpenGL 4.0");

        // Set up the coordinate system
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Draw the RNA bonds
        drawRNABonds(fold, rna_sequence);

        // Draw the RNA dots
        drawRNADots(rna_sequence);

        // Render debug information
        std::string zoom_info = "Zoom: " + std::to_string(zoom_factor);
        renderText(-0.9f, 0.7f, zoom_info);

        std::string offset_info = "Offset: " + std::to_string(pan_offset);
        renderText(-0.9f, 0.6f, offset_info);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}