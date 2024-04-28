/**
 * @file main.cpp
 * @author Adarsh Das (saphereye.github.io)
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "rna_folding.hh"
#include "herrlog.hh"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//! Global variable to store rna name
std::string rna_name;

//! Number of nucleotides in input
int number_of_nucleotides = 0;
//! Number of bonds in input
int number_of_bonds = 0;

void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

//! OpenGL reference to the RNA structure image
GLuint texture;

//! Global variables to keep track of RNA structure image width
int textureWidth;
//! Global variables to keep track of RNA structure image width
int textureHeight;

/**
 * @brief Loads an RGBA image
 *
 * @param filename
 */
void loadTexture(const char* filename) {
    Logger::trace("Loading the image ...");
    GLint maxTextureSize;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    textureWidth = width;
    textureHeight = height;
    Logger::trace("Trying to load texture of size: {}x{}", width, height);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        Logger::warn("Failed to load texture: {}", filename);
    }
    stbi_image_free(data);
}

//! Pan along the x-axis
float pan_x = 0.0f;
//! Pan along the y-axis
float pan_y = 0.0f;
//! Zoom factor
float zoom = 1.0f;

/**
 * @brief Draws a textured quad on the screen. Keeps the aspect ratio of the
 * image intact
 *
 */
void drawTexturedQuad() {
    glPushMatrix();

    glTranslatef(pan_x, pan_y, 0.0f);
    glScalef(zoom, zoom, 1.0f);

    float aspectRatio =
        static_cast<float>(textureWidth) / static_cast<float>(textureHeight);
    float halfWidth = aspectRatio / 2.0f;

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(-halfWidth, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(halfWidth, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(halfWidth, 0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(-halfWidth, 0.5f);
    glEnd();

    glPopMatrix();
}

//! Keeps track of which key was pressed on the keyboard
bool keys[256] = {false};

/**
 * @brief Callback function for keyboard events (Down press)
 *
 * @param key
 * @param x
 * @param y
 */
void keyboardDown(unsigned char key, int x, int y) { keys[key] = true; }

/**
 * @brief Callback function for keyboard events (Up press)
 *
 * @param key
 * @param x
 * @param y
 */
void keyboardUp(unsigned char key, int x, int y) { keys[key] = false; }

/**
 * @brief Callback function for updating the keyboard input
 *
 */
void update() {
    if (keys['w']) pan_y -= 0.05f;
    if (keys['s']) pan_y += 0.05f;
    if (keys['a']) pan_x += 0.05f;
    if (keys['d']) pan_x -= 0.05f;
    if (keys['e']) zoom *= 1.1f;
    if (keys['q']) zoom *= 0.9f;
    if (keys[27]) glutLeaveMainLoop();

    glutPostRedisplay();
}

/**
 * @brief Callback function called when reshaping window
 *
 * @param width
 * @param height
 */
void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    float aspect = (float)width / (float)height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width >= height) {
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    } else {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }

    glMatrixMode(GL_MODELVIEW);
}

/**
 * @brief Callback function for displaying the image and the text
 *
 */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    drawTexturedQuad();

    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
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
        rna_name = std::string(argv[1]);
        file.open(rna_name);
    } else {
        file.open("rna/" + rna_name + ".rna");
    }

    if (!file) {
        Logger::error("Failed to open the file.");
    }

    std::string rna_sequence;
    std::getline(file, rna_sequence);
    number_of_nucleotides = rna_sequence.size();
    const int minimal_loop_length = 5;

    std::vector<std::pair<int, int>> fold;
    traceback(create_matrix(rna_sequence, minimal_loop_length), rna_sequence,
              fold, 0, rna_sequence.size() - 1);

    std::string dot_notation = dot_write(rna_sequence, fold);

    number_of_bonds = rna_score(rna_sequence, minimal_loop_length);
    Logger::info("Input RNA sequence: {}", rna_sequence);
    Logger::info("Dot-bracket notation: {}", dot_notation);
    Logger::info("Total number of nucleotides: {}", rna_sequence.size());
    Logger::info("Total number of bonds: {}", number_of_bonds);
    Logger::trace("Creating the image ...");
    dot_bracket_to_dot(rna_sequence, dot_notation);
    Logger::trace("Image created successfully.");
    Logger::trace("Creating graphics ...");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Image Display");
    glutFullScreen();

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        Logger::error("Failed to initialize GLEW: {}", glewGetErrorString(err));
        return -1;
    }

    loadTexture("rna.png");

    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutIdleFunc(update);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();

    glutMainLoop();

    Logger::trace("Exiting program");
    return 0;
}
