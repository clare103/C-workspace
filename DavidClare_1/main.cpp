//
//  main.cpp
//  DavidClare_1
//
//  Created by David Clare on 1/5/15.
//  Copyright (c) 2015 David Clare. All rights reserved.
//


#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

#define LEFT 1
#define RIGHT 2

void init()
{
    glClearColor(0,0,0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
};

int output_bitmap()
{
    int len;
    
    char bloop[] = "ahfksdfgskdjh";
    len = (int) strlen(bloop);
    
    
    
    glRasterPos2f(-1, 0);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, bloop[i]);
    }

    return 0;
    
};


int output_stroke()
{
    
    int len;
    
    char bloop[] = "ahfksdfgskdjh";
    len = (int) strlen(bloop);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.0005, 0.0005, 0.0005);
    glTranslatef(-1*2000, 0*2000, 0);
    for (int i = 0; i < len; i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, bloop[i]);
        
    }
    return 0;
};



void processMenuEvents(int option) {
    
    if(option == 1)
    {
        output_bitmap();
    }
    else
    {
        output_stroke();
    }
    
    
};


void createGLUTMenus() {
    
    int menu;
    
    // create the menu and
    // tell glut that "processMenuEvents" will
    // handle the events
    menu = glutCreateMenu(processMenuEvents);
    
    //add entries to our menu
    glutAddMenuEntry("BITMAP",LEFT);
    glutAddMenuEntry("STROKE",RIGHT);
    
    
    // attach the menu to the right button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}




void commented_code()
{
    //drawOneLine(50.0, 100.0, 150.0, 200.0);
    //drawOneLine(100.0, 100.0, 0.0, 0.0);
    
    //draws grid
    
    /*
     glVertex2i(100, 0);
     glVertex2i(100, 150);
     glEnd();
     glBegin(GL_LINES);
     glVertex2i(0, 75);
     glVertex2i(200, 75);
     
     //glVertex2i(150, 75);
     //glVertex2i(150, 75);
     
     glEnd();
     
     
     //glBegin(GL_LINES);
     
     glColor3f(1.0f, 1.0f, 1.0f);
     glRasterPos2f(25.0f, 10.0f);
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
     */
    
    //output(20.0f, 15.0f, 'S');

}


void output()
{
    
    createGLUTMenus();
    
};

void lineSeg()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glLoadIdentity();
    
    
    
    //output();
    createGLUTMenus();
    
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
