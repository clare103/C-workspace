//
//  main.cpp
//  DavidClare_2
//
//  Created by David Clare on 1/12/15.
//  Copyright (c) 2015 David Clare. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();


GLFloat vertex[4][3] = {{0.0, -20.0,0.0}, {0.0,sqrt(7500.0

void init()
{
    
    
    glClearColor(0,0,0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);

};

void commented_code()
{
    //drawOneLine(50.0, 100.0, 150.0, 200.0);
    //drawOneLine(100.0, 100.0, 0.0, 0.0);
    
    //draws grid
    
    /*
     glVertex2i(100, 0);
     glVertex2i(100, 150);
     glEnd();
     glBegin(GL_POINT);
     glVertex2i(0, 75);
     glVertex2i(200, 75);
     */
     //glVertex2i(150, 75);
     //glVertex2i(150, 75);
     
     //glEnd();
     
     
     //glBegin(GL_LINES);
     
     //glColor3f(1.0f, 1.0f, 1.0f);
     //glRasterPos2f(25.0f, 10.0f);
     //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
    
    
    //output(20.0f, 15.0f, 'S');
    
}


void plot_points()
{
    glBegin(GL_POINTS);
    glVertex2i(0, 75);
    glVertex2i(200, 75);
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();

}


void lineSeg()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glLoadIdentity();
    
    
    plot_points();
    
    glEnd();
    glFlush();
}


int main(int argc, char ** argv) {
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("My Sexy Window");
    
    
    init();
    
    glutDisplayFunc(lineSeg);
    glutMainLoop();
    
    return 0;
}
