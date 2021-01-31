#include<iostream>
#include<cmath>
#include<vector>
#include<GL/glut.h>
#include "trie.h"

using namespace std;

const double PI = acos(-1.0);

struct point
{
    double x;
    double y;
};

vector<vector<pair<pair<int, int>, int>>> t;
vector<vector<pair<point, int>>> pts;

point center;
int a;
float r = 0.01;

void drawcircle()
{
    int n = 100;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n;i++)
    {
        glVertex2f(center.x+r * cos(2 * PI * i / n), center.y+r * sin(2 * PI * i / n));
    }
    glEnd();
    glFlush();
}

int main(int argc,char ** argv)
{
    glClearColor(1.0f, 1.0f, 1.0f);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("test");
    for(auto i:pts)
    {
        center = i.first;
        a = i.second;
        glutDisplayFunc(drawcircle);
    }
    glutMainLoop();
    return 0;
}