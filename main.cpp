#include <windows.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>

void renderScene() {
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 

    glutInitWindowSize(1024, 768);
    glutCreateWindow("Test");

    glutDisplayFunc(renderScene); // Add renderScene() as a callback to GLUT's rendering call
    
    glutMainLoop(); // Give control to GLUT
    return 0;
}