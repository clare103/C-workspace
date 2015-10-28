#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

using namespace std;

double view = 2.0;
static float angle = 0.0;

int location[8] = {0};

void init();
void makeCircles();
void resize(int, int);
void next_location(int);
void makeMenu();
void menuCallback(int);
void draw();


enum {Standard, Above, Below};
float ***planets = new float**[360];
static float planetMultiplier[8][2] = {{.5, 2}, {.7, .4}, {1.0, 2}, {1.5, 2.5}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}, {4.5, 3.0}};
static float planetColors[8][3] = {{1.0, 0.0, 0.0}, {1.0,0.0,0.0}, {0.0,0.0,1.0}, {1.0,0.0,0.0}, {1.0,0.0,0.0}, {1.0,0.0,1.0}, {0.0,1.0,0.0}, {0.0,1.0,0.0}};
static float planetRadius[8] = {0.2, 0.2, 0.3, 0.2, 0.4, 0.4, 0.2, 0.2};
static float planetMoveAmount[8] = {3, 6, 7, 8, 8, 4, 5, 1};
static int menuChoice = 0;


void init(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void makeMenu(){
    glutCreateMenu(menuCallback);
    glutAddMenuEntry("Standard", Standard);
    glutAddMenuEntry("Below", Below);
    glutAddMenuEntry("Above", Above);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menuCallback(int option){
    if(option == Below){view=-10.0;}
    else if(option == Standard){view=0.0;}
    else if(option == Above){view=10.0;}
    glutPostRedisplay();
}

void makeCircles(float ***planets){
    for (int i = 0; i < 360; i++) {
        planets[i] = new float*[8];
        for (int j = 0; j < 8; j++){
            planets[i][j] = new float[2];
        }
    }
    
    for (int i = 0; i < 360; i++){
        for(int j = 0; j < 8; j++){
            planets[i][j][0] = sin(j*3.1416/180);
            cout << planets[i][j][0] << endl;
            planets[i][j][1] = cos(j*3.1416/180);
            cout << planets[i][j][1] << endl;
        }
    }
}

void draw(){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //sun
    glPushMatrix();
    gluLookAt (0.0, 10.0, view, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glColor3f(1.0,1.0,0.0);
    glutSolidSphere(.5,15,15);
    glPopMatrix();
    
    //planets
    for (int i = 0; i < 8; i++){
        glPushMatrix();
        gluLookAt (0.0, 10.0, view, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
        if(location[i]>=360){location[i] = 0;}
        glTranslatef(planets[location[i]][i][0]*planetMultiplier[i][0],planets[location[i]][i][1]*planetMultiplier[i][1], 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glColor3f(planetColors[i][0],planetColors[i][1],planetColors[i][2]);
        glutSolidSphere (planetRadius[i], 15, 15);
        
        //saturn rings
        if (i == 5){
            int j = 0;
            glColor3f(0.0,1.0,0.0);
            glBegin(GL_QUAD_STRIP);
            for(int j = 0; j < 360; j++)
            {
                glVertex3f(sin(j*3.1416/180)*0.5, cos(j*3.1416/180)*0.5, 0 );
                glVertex3f(sin(j*3.1416/180)*0.7, cos(j*3.1416/180)*0.7, 0 );
            }
            glEnd();
            glRotatef(angle, 0.0, 0.0, 1.0);
        }
        glPopMatrix();
    }
    glFlush ();
}


void resize(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}


//planet location
void changeLocation(int value)
{
    angle += 15.0;
    glutPostRedisplay();
    for (int i = 0; i < 8; i++){location[i] += planetMoveAmount[i];}
    glutPostRedisplay();
    glutTimerFunc(100, changeLocation, 0);
    
}


int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Solar System");
    init();
    glutDisplayFunc(draw);
    glutReshapeFunc(resize);
    makeMenu();
    makeCircles(planets);
    glutTimerFunc(100, changeLocation, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}