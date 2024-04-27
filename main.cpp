/**
 * @file main.cpp
 * @author Adarsh Das (saphereye.github.io)
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>

#include "rna_folding.hh"
#include "herrlog.hh"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Global variables to store the RNA information
const std::string rna_name =
    // "Homo sapiens (human) RNA, U5D small nuclear 1 (RNU5D-1)";
    "ACA box 91 (SNORA91)";
// "Homo sapiens (human) small nucleolar RNA (SNORD43)";
// "Homo sapiens (human) microRNA hsa-mir-921 precursor";
// "Homo sapiens U7 small nuclear RNA";
// "Homo sapiens (human) small nucleolar RNA (SNORA81)";
// "Murari";
// "Vansh";
int number_of_nucleotides =
    0;  // Update this value when you read the RNA sequence
int number_of_bonds =
    0;  // Update this value when you calculate the RNA folding

// Function to draw text
void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

// Global variable to store the texture
GLuint texture;

// Global variables to store the texture size
int textureWidth, textureHeight;

// Function to load texture from file
void loadTexture(const char* filename) {
    // Check maximum texture size
    GLint maxTextureSize;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Adjust texture filtering mode
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);  // Try GL_NEAREST
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_NEAREST);  // Try GL_NEAREST

    // Load texture image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    textureWidth = width;
    textureHeight = height;
    Logger::info("Trying to load texture of size: {}x{}", width, height);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        Logger::warn("Failed to load texture: {}", filename);
    }
    stbi_image_free(data);
}

// Global variables to store the pan offset
float pan_x = 0.0f;
float pan_y = 0.0f;

// Global variable to store the zoom level
float zoom = 1.0f;

// Function to draw textured quad
void drawTexturedQuad() {
    glPushMatrix();  // Save the current transformation
    // Apply the pan transformation
    glTranslatef(pan_x, pan_y, 0.0f);
    glScalef(zoom, zoom, 1.0f);

    float aspectRatio =
        static_cast<float>(textureWidth) / static_cast<float>(textureHeight);
    float halfWidth = aspectRatio / 2.0f;

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);  // Flip the y-coordinate
    glVertex2f(-halfWidth, -0.5f);
    glTexCoord2f(1.0f, 1.0f);  // Flip the y-coordinate
    glVertex2f(halfWidth, -0.5f);
    glTexCoord2f(1.0f, 0.0f);  // Flip the y-coordinate
    glVertex2f(halfWidth, 0.5f);
    glTexCoord2f(0.0f, 0.0f);  // Flip the y-coordinate
    glVertex2f(-halfWidth, 0.5f);
    glEnd();

    glPopMatrix();  // Restore the previous transformation
}

// Array to track the state of each key
bool keys[256] = {false};

// Callback function for keyboard input
void keyboardDown(unsigned char key, int x, int y) { keys[key] = true; }

// Callback function for keyboard input
void keyboardUp(unsigned char key, int x, int y) { keys[key] = false; }

// Function to update the state of the program based on the state of the keys
void update() {
    if (keys['w']) pan_y -= 0.05f;
    if (keys['s']) pan_y += 0.05f;
    if (keys['a']) pan_x += 0.05f;
    if (keys['d']) pan_x -= 0.05f;
    if (keys['e']) zoom *= 1.1f;
    if (keys['q']) zoom *= 0.9f;
    if (keys[27]) glutLeaveMainLoop();  // Escape key

    // Redraw the scene
    glutPostRedisplay();
}

// Callback function for window resizing
void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    // Calculate the aspect ratio of the window
    float aspect = (float)width / (float)height;

    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width >= height) {
        // Window is wider than it is tall, so extend the x-coordinate range
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    } else {
        // Window is taller than it is wide, so extend the y-coordinate range
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }

    // Switch back to the modelview matrix
    glMatrixMode(GL_MODELVIEW);
}

// Callback function for rendering
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Draw the textured quad
    drawTexturedQuad();

    // Draw the RNA information
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);  // Set the text color to white
    drawText(("Current RNA: " + rna_name).c_str(), -1.0f, 0.9f);
    drawText(("Number of nucleotides: " + std::to_string(number_of_nucleotides))
                 .c_str(),
             -1.0f, 0.85f);
    drawText(("Number of bonds: " + std::to_string(number_of_bonds)).c_str(),
             -1.0f, 0.8f);

    drawText("Controls:", -1.0f, 0.7f);
    drawText(("(x, y): " + std::to_string(pan_x) + ", " + std::to_string(pan_y))
                 .c_str(),
             -1.0f, 0.65f);
    drawText(("Zoom: " + std::to_string(zoom)).c_str(), -1.0f, 0.6f);

    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    std::ifstream file;
    if (argc >= 1) {
        std::string rna_name = argv[1];
        file.open(rna_name);
    } else {
        file.open("rna/" + rna_name + ".rna");
    }

    if (!file) {
        Logger::error("Failed to open the file.");
    }

    // Read the RNA sequence from the file
    std::string rna_sequence;
    std::getline(file, rna_sequence);
    number_of_nucleotides = rna_sequence.size();
    const int minimal_loop_length = 4;

    std::vector<std::pair<int, int>> fold;
    traceback(create_matrix(rna_sequence, minimal_loop_length), rna_sequence,
              fold, 0, rna_sequence.size() - 1);

    std::string dot_notation = dot_write(rna_sequence, fold);
    // Count the number of bonds in the RNA sequence
    number_of_bonds = rna_score(rna_sequence, minimal_loop_length);
    Logger::info("Input RNA sequence: {}", rna_sequence);
    Logger::info("Dot-bracket notation: {}", dot_notation);
    Logger::info("Total number of nucleotides: {}", rna_sequence.size());
    Logger::info("Total number of bonds: {}", number_of_bonds);
    Logger::info("Creating the image ...");
    dot_bracket_to_dot(rna_sequence, dot_notation);
    Logger::info("Image created successfully.");
    Logger::info("Creating graphics ...");

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Image Display");
    glutFullScreen();

    // Initialize GLEW
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        Logger::error("Failed to initialize GLEW: {}", glewGetErrorString(err));
        return -1;
    }

    // Load the texture
    loadTexture("rna.png");

    // Register callback functions
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutIdleFunc(update);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // Set clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();

    // Enter the GLUT event loop
    glutMainLoop();

    Logger::info("Exiting program");
    return 0;
}
