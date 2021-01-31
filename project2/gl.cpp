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
typedef vector<vector<pair<pair<int, int>, int>>> trie01;
trie01 t;
vector<vector<pair<point, int>>> pts;

int layer;
float r;
void update(trie a)
{
    t = a.putout();
    layer = t.size();
}

float r = 0.04;
//上下行间距为一个半径，最上面最下面留两个半径

point center;
int a;


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
        for(auto j:i)
        {
        center = j.first;
        a = j.second;
        glutDisplayFunc(drawcircle);
        }
    }
    glutMainLoop();
    return 0;
}