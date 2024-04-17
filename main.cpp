#include <GLFW/glfw3.h>

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "rna_folding.cpp"

void drawRNADots(const std::string& rna_sequence) {
    // Calculate the spacing between dots based on the window size and RNA
    // sequence length
    float dot_spacing = 2.0f / static_cast<float>(rna_sequence.size() + 1);

    // Start drawing the dots
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    for (size_t i = 0; i < rna_sequence.size(); ++i) {
        // Calculate the x-coordinate for the dot
        float x = -1.0f + dot_spacing * (i + 1);

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
                glColor3f(0.5f, 0.5f, 0.5f);  // Gray for unknown nucleotides
                break;
        }

        // Draw the dot at the calculated position
        glVertex2f(x, 0.0f);
    }
    glEnd();
}

void drawRNABonds(const std::vector<std::pair<int, int>>& traceback,
                  const std::string& rna_sequence) {
    // Set the color for all bonds
    glColor3f(0.0f, 1.0f, 0.0f);  // Green color

    // Calculate the spacing between dots based on the window size and RNA
    // sequence length
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
    // std::string rna_sequence =
    //     "AAUCCCCCGUGCCCAUAGCGGCGUGGAACCACCCGUUCCCAUUCCGAACACGGAAGUGAAACGCGCCAGC"
    //     "GCCGAUGGUACUGGGCGGGCGACCGCCUGGGAGAGUAGGUCGGUGCGGGGGA";
    std::string rna_sequence = "GGGAAAUCCGGAACCGG";

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

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

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

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}