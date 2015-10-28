//
//  main.cpp
//  DavidClare_4
//
//  Created by David Clare on 1/12/15.
//  Copyright (c) 2015 David Clare. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>



static float tetrahedronAngle = 0.0f;

// read time stamp counter
// this instruction is available on x86, x64
// the result is stored in EDX:EAX

/*
unsigned long long rdtsc()
{
    __asm { rdtsc }
}*/

void drawTetrahedron() {
    
    static const float tetrahedron[][3] = {
        {0.0f, 1.0f, 0.0f}, {0.943f, -0.333f, 0.0f}, {-0.471f, -0.333f, 0.8165f
        }, {-0.471f, -0.333f, -0.8165f}};
    static const float materialAmbientColor[][3] = {
        {1.0f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f}};
    static const float materialSpecularColor[][3] = {
        {1.0f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f}};
    
    static const int point[] = {1, 2, 0, 3, 1}; // triangle strip
    
    glPushMatrix();
    
    glRotatef(tetrahedronAngle, 0.0f, 1.0f, 0.0f);
    
    for (int i = 0; i < 3 /* sides */ ; i++) {
        glBegin(GL_TRIANGLE_STRIP);
        
        glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbientColor[i]);
        glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecularColor[i]);
        
        glVertex3fv(tetrahedron[point[i]]);
        glVertex3fv(tetrahedron[point[i + 1]]);
        glVertex3fv(tetrahedron[point[i + 2]]);
        
        glEnd();
    }
    
    glPopMatrix();
}
void initLighting() {
    const float lightPosition[][4] = { {0.0f, 25.0f, 0.0f, 1.0f}};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition[0]);
    
    const float lightAmbient[][3] = { {0.15f, 0.15f, 0.15f}};
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient[0]);
    
    const float lightSpecular[][3] = { {0.05f, 0.05f, 0.05f}};
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular[0]);
    
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1e-3);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 1e-3);
    
    glShadeModel(GL_FLAT);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glEnable(GL_LIGHTING);
    
    glPushMatrix();
    glTranslatef(0.0f, -1.5f, -7.5f); // observer position
    
    // update tetrahedron angle
    unsigned long long t = rdtsc();
    printf("\n%llu", t);
    tetrahedronAngle = ((long)(t >> 24/* scaling */)) % 360 /* degrees */ ;
    
    drawTetrahedron();
    
    glPopMatrix();
    
    glutSwapBuffers();
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, (GLfloat)w / h, 0.125, 1e4);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 0x1b: // escape
            exit(0);
            break;
    }
}

void idleFunc() {
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Multicolor tetrahedron");
    glutFullScreen();
    initLighting();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idleFunc);
    glutMainLoop();
    
    return 0;
}



