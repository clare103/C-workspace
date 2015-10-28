//
//  main.cpp
//  DavidClare_3
//
//  Created by David Clare on 1/7/15.
//  Copyright (c) 2015 David Clare. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <GLKit/glkit.h>


void init()
{
    
    //GLKMatrix4MakeOrtho( 0.0, 200.0, 0.0, 150.0);
    
    glClearColor(0,0,0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
    //GLKMatrix4MakeOrtho( 0.0, 200.0, 0.0, 150.0);
    // int mode = 0;
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

void glutMenuEvents(int option, char *word)
{
    int len, i;
    len = (int) strlen(word);
    
    
    if(option == 1)
    {
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        
        glRasterPos2f(1, 0);
        //len = (int) strlen(string);
        for (i = 0; i < len; i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, word[i]);
        }
        
       // glRasterPos2f(1 , 0);
        //len = (int) strlen(string);
        for (i = 0; i < len; i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, word[i]);
        }
    }
    else
    {
        glutAttachMenu(GLUT_LEFT_BUTTON);
        
        
        
    }
};

void output(int x, int y, char *string)
{
    
    int len, i;
    len = (int) strlen(string);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
        glRasterPos2f(x, y);
        //len = (int) strlen(string);
        for (i = 0; i < len; i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
        }
        
    
    else if(mode ==1)
    {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glScalef(0.0005, 0.0005, 0.0005);
        glTranslatef(x*2000, y*2000, 0);
        for (i = 0; i < len; i++)
        {
            glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);
        }
    }
    
};

void lineSeg()
{
    //glBegin(GL_LINES);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glLoadIdentity();
    
    char bloop[] = " ahfksdfgskdjh";
    
    output(1, -1, 0, bloop);
    
    glEnd();
    glFlush();
}




void drawText(char *string)
{
    int i, len;
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(25.0f, 10.0f);
    
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -1.0f);
    
    for (i = 0, len = strlen(string); i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, (int)string[i]);
    }
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
