#include<windows.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

typedef float Matrix4 [4][4];

Matrix4 theMatrix;
static GLfloat input[4][3]=
{
    {0,30,30},{30,30,60},{30,0,10},{0,0,0}
};

float output[4][3];
float sx,sy,sz;


void setIdentityM(Matrix4 m)
{
for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
        m[i][j]=(i==j);
}


void scale(int sx,int sy,int sz)
{
    theMatrix[0][0]=sx;
    theMatrix[1][1]=sy;
    theMatrix[2][2]=sz;
}


void multiplyM()
{

for(int i=0;i<8;i++)
 {
    for(int j=0;j<3;j++)
    {
        output[i][j]=0;
        for(int k=0;k<3;k++)
        {
            output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];
        }
    }
}

}
void Axes(void)
{
 glColor3f (0.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex2s(-1000 ,0);
 glVertex2s( 1000 ,0);
 glEnd();
 glBegin(GL_LINES);
 glVertex2s(0 ,-1000);
 glVertex2s(0 , 1000);
 glEnd();
}
void draw(float a[8][3],int r,int g,int b)
{

glBegin(GL_QUADS);
glColor3f (r,g,b);
glVertex3fv(a[0]);
glVertex3fv(a[1]);
glVertex3fv(a[2]);
glVertex3fv(a[3]);
glEnd();
}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
Axes();
glColor3f(1.0,0.0,0.0);
draw(input,1.0,1.0,0.0);
setIdentityM(theMatrix);

scale(sx,sy,sz);
multiplyM();

draw(output,1.0,0.0,1.0);
glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1362,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Scaling");
    init();
        cout<<"\nEnter Sx,Sy & Sz: \n";
        cin>>sx>>sy>>sz;
    glutDisplayFunc(display);
    glutMainLoop();
return 0;
}
