#include <GL/freeglut.h>
#include <GLFW/glfw3.h>

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
    // float dot_spacing = 2.0f / static_cast<float>(rna_sequence.size() + 1);
    float dot_spacing = 0.1f / zoom_factor;
    float start_x = -1.0f + pan_offset;

    // Start drawing the dots
    glPointSize(10.0f);
    for (size_t i = 0; i < rna_sequence.size(); ++i) {
        glBegin(GL_POINTS);
        // Calculate the x-coordinate for the dot
        float x = start_x + dot_spacing * (i + 1);

        // Set the color based on the nucleotide
        switch (rna_sequence[i]) {
            case 'A':
                glColor3f(1.0f, 0.0f, 0.0f);  // Red for A
                break;
            case 'U':
                glColor3f(0.0f, 1.0f, 0.0f);  // Green for U
                break;
            case 'G':
                glColor3f(0.0f, 0.0f, 1.0f);  // Blue for G
                break;
            case 'C':
                glColor3f(1.0f, 1.0f, 0.0f);  // Yellow for C
                break;
            default:
                glColor3f(0.5f, 0.5f, 0.5f);  // Gray for wrong nucleotide
                break;
        }

        // Draw the dot at the calculated position
        glVertex2f(x, -0.8f);
        glEnd();

        // Render nucleotide name below the dot
        std::string nucleotide_name = std::string(1, rna_sequence[i]);
        renderText(x - 0.02f, -0.9f, nucleotide_name);
    }

    // Debug information: Number of nucleotides
    std::string nucleotide_count =
        "Nucleotides: " + std::to_string(rna_sequence.size());
    renderText(-0.9f, 0.9f, nucleotide_count);
}

void drawRNABonds(const std::vector<std::pair<int, int>>& traceback,
                  const std::string& rna_sequence) {
    // Set the color for all bonds
    glColor3f(0.0f, 1.0f, 0.0f);  // Green color

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
                pan_speed = 0.1f;
                break;
            case GLFW_KEY_RIGHT:
                pan_speed = -0.1f;
                break;
            case GLFW_KEY_EQUAL:
                zoom_factor /= 1.1f;
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

int main(int argv, char** argc) {
    std::ifstream file("rna/Thermus thermophilus 5S rRNA.rna");
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
    GLFWwindow* window =
        glfwCreateWindow(800, 600, "RNA Sequence Visualization", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

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