#include<GL/glut.h>
#include<GL/glu.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);
}

void ball()
{
    glColor3ub(255,0,0);
    glutSolidSphere(0.10,25,25);
}

void basket()
{
   glColor3ub(225,225,225);
   glutWireCone(0.25,0.35,10,10);  //0.20-radius of the cone
}

void tile()
{
    glColor3ub(0,0,225);
    glutSolidCube(0.5);
}

float ballX=0,ballY=+1.80;
float basketX=0,basketY=-1.50;
float tileX=0.50,tileY=+1.80;
float ballspeed=0;  //Used to Increase the Ball Speed
int rand();   //Used to make Ball Fall from Random Positions
int r;        //Used to Store the Random
int flagout=0; //When Ball touches Basket,value is set to 1
int count=0;   //Use to increase the Ball Speed
int point=0;   //Use to Count Total Points


void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);   //Blue color
    glColor3ub(145,226,250);
    glVertex2f(2.0,2.0);
    glVertex2f(-2.0,2.0);
    glVertex2f(-2.0,-2.0);
    glVertex2f(2.0,-2.0);
    glEnd();

    glBegin(GL_QUADS);   //Dark Green Color
    glColor3ub(0,200,0);
    glVertex2f(2.0,-2.0);
    glVertex2f(2.0,-1.30);
    glVertex2f(-2.0,-1.30);
    glVertex2f(-2.0,-2.0);
    glEnd();

    glBegin(GL_QUADS);   //Dark Brown Color(Ground)
    glColor3ub(165,42,42);
    glVertex2f(2.0,-2.0);
    glVertex2f(2.0,-1.85);
    glVertex2f(-2.0,-1.85);
    glVertex2f(-2.0,-2.0);
    glEnd();

    glBegin(GL_QUADS);      //Code for Tree-1 Stem
    glColor3ub(139,69,19);
    glVertex2f(-1.80,-1.30);
    glVertex2f(-1.70,-1.30);
    glVertex2f(-1.70,-1.10);
    glVertex2f(-1.80,-1.10);
    glEnd();

    glBegin(GL_TRIANGLES);  //Code for Tree-1 Branches
    glColor3ub(0,100,0);
    glVertex2f(-2.00,-1.10);
    glVertex2f(-1.50,-1.10);
    glVertex2f(-1.75,-0.70);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-1.95,-0.90);
    glVertex2f(-1.55,-0.90);
    glVertex2f(-1.75,-0.50);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-1.90,-0.70);
    glVertex2f(-1.60,-0.70);
    glVertex2f(-1.75,-0.30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-1.85,-0.50);
    glVertex2f(-1.65,-0.50);
    glVertex2f(-1.75,-0.10);
    glEnd();

    glBegin(GL_QUADS);     //Code for Tree-2 Stem
    glColor3ub(139,69,19);
    glVertex2f(-1.25,-1.35);
    glVertex2f(-1.15,-1.35);
    glVertex2f(-1.15,-1.25);
    glVertex2f(-1.25,-1.25);
    glEnd();

    glBegin(GL_TRIANGLES);    //Code for Tree-2 Branches
    glColor3ub(0,100,0);
    glVertex2f(-1.40,-1.25);
    glVertex2f(-1.00,-1.25);
    glVertex2f(-1.20,-0.90);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-1.35,-1.10);
    glVertex2f(-1.05,-1.10);
    glVertex2f(-1.20,-0.80);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-1.30,-0.95);
    glVertex2f(-1.10,-0.95);
    glVertex2f(-1.20,-0.75);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-1.25,-0.85);
    glVertex2f(-1.15,-0.85);
    glVertex2f(-1.20,-0.70);
    glEnd();

    glBegin(GL_QUADS);     //Code for Tree-3 Stem
    glColor3ub(139,69,19);
    glVertex2f(+1.25,-1.40);
    glVertex2f(+1.15,-1.40);
    glVertex2f(+1.15,-1.25);
    glVertex2f(+1.25,-1.25);
    glEnd();

    glBegin(GL_TRIANGLES);    //Code for Tree-3 Branches
    glColor3ub(0,100,0);
    glVertex2f(+1.40,-1.25);
    glVertex2f(+1.00,-1.25);
    glVertex2f(+1.20,-0.90);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(+1.35,-1.10);
    glVertex2f(+1.05,-1.10);
    glVertex2f(+1.20,-0.80);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(+1.30,-0.95);
    glVertex2f(+1.10,-0.95);
    glVertex2f(+1.20,-0.75);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(+1.25,-0.85);
    glVertex2f(+1.15,-0.85);
    glVertex2f(+1.20,-0.70);
    glEnd();

    glBegin(GL_QUADS);      //Code for Tree-4 Stem
    glColor3ub(139,69,19);
    glVertex2f(+1.80,-1.30);
    glVertex2f(+1.70,-1.30);
    glVertex2f(+1.70,-1.10);
    glVertex2f(+1.80,-1.10);
    glEnd();

    glBegin(GL_TRIANGLES);  //Code for Tree-4 Branches
    glColor3ub(0,100,0);
    glVertex2f(+2.00,-1.10);
    glVertex2f(+1.50,-1.10);
    glVertex2f(+1.75,-0.80);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(+1.95,-0.95);
    glVertex2f(+1.55,-0.95);
    glVertex2f(+1.75,-0.65);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(+1.90,-0.80);
    glVertex2f(+1.60,-0.80);
    glVertex2f(+1.75,-0.50);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(+1.85,-0.65);
    glVertex2f(+1.65,-0.65);
    glVertex2f(+1.75,-0.35);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-1
    glColor3ub(0,128,0);
    glVertex2f(-1.75,-1.60);
    glVertex2f(-1.68,-1.60);
    glVertex2f(-1.73,-1.53);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.71,-1.60);
    glVertex2f(-1.65,-1.60);
    glVertex2f(-1.70,-1.50);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.68,-1.60);
    glVertex2f(-1.63,-1.60);
    glVertex2f(-1.66,-1.56);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-2
    glColor3ub(0,128,0);
    glVertex2f(-1.64,-1.60);
    glVertex2f(-1.58,-1.60);
    glVertex2f(-1.61,-1.53);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.59,-1.60);
    glVertex2f(-1.55,-1.60);
    glVertex2f(-1.58,-1.50);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.56,-1.60);
    glVertex2f(-1.51,-1.60);
    glVertex2f(-1.54,-1.56);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-3
    glColor3ub(0,128,0);
    glVertex2f(-1.14,-1.70);
    glVertex2f(-1.08,-1.70);
    glVertex2f(-1.11,-1.63);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.09,-1.70);
    glVertex2f(-1.05,-1.70);
    glVertex2f(-1.08,-1.60);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.06,-1.70);
    glVertex2f(-1.01,-1.70);
    glVertex2f(-1.04,-1.66);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-4
    glColor3ub(0,128,0);
    glVertex2f(-1.70,-1.30);
    glVertex2f(-1.63,-1.30);
    glVertex2f(-1.68,-1.23);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.66,-1.30);
    glVertex2f(-1.60,-1.30);
    glVertex2f(-1.65,-1.20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.63,-1.30);
    glVertex2f(-1.58,-1.30);
    glVertex2f(-1.61,-1.26);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-5
    glColor3ub(0,128,0);
    glVertex2f(-1.64,-1.30);
    glVertex2f(-1.58,-1.30);
    glVertex2f(-1.61,-1.23);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.59,-1.30);
    glVertex2f(-1.55,-1.30);
    glVertex2f(-1.58,-1.20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.56,-1.30);
    glVertex2f(-1.51,-1.30);
    glVertex2f(-1.54,-1.26);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-6
    glColor3ub(0,128,0);
    glVertex2f(-1.51,-1.30);
    glVertex2f(-1.45,-1.30);
    glVertex2f(-1.48,-1.23);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.50,-1.30);
    glVertex2f(-1.46,-1.30);
    glVertex2f(-1.49,-1.20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-1.47,-1.30);
    glVertex2f(-1.42,-1.30);
    glVertex2f(-1.45,-1.26);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-7
    glColor3ub(0,128,0);
    glVertex2f(0.24,-1.45);
    glVertex2f(0.18,-1.45);
    glVertex2f(0.21,-1.38);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(0.19,-1.45);
    glVertex2f(0.15,-1.45);
    glVertex2f(0.18,-1.40);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(0.16,-1.45);
    glVertex2f(0.11,-1.45);
    glVertex2f(0.14,-1.41);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-8
    glColor3ub(0,128,0);
    glVertex2f(0.64,-1.70);
    glVertex2f(0.58,-1.70);
    glVertex2f(0.61,-1.63);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(0.59,-1.70);
    glVertex2f(0.55,-1.70);
    glVertex2f(0.58,-1.60);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(0.56,-1.70);
    glVertex2f(0.51,-1.70);
    glVertex2f(0.54,-1.66);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-9
    glColor3ub(0,128,0);
    glVertex2f(+1.34,-1.80);
    glVertex2f(+1.28,-1.80);
    glVertex2f(+1.31,-1.73);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.29,-1.80);
    glVertex2f(+1.25,-1.80);
    glVertex2f(+1.28,-1.70);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.26,-1.80);
    glVertex2f(+1.21,-1.80);
    glVertex2f(+1.24,-1.76);
    glEnd();

    glBegin(GL_TRIANGLES);     //Code for Grass-10
    glColor3ub(0,128,0);
    glVertex2f(+1.55,-1.60);
    glVertex2f(+1.48,-1.60);
    glVertex2f(+1.53,-1.53);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.51,-1.60);
    glVertex2f(+1.45,-1.60);
    glVertex2f(+1.50,-1.50);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.48,-1.60);
    glVertex2f(+1.43,-1.60);
    glVertex2f(+1.44,-1.56);
    glEnd();

     glBegin(GL_TRIANGLES);   //Code for Grass-11
    glColor3ub(0,128,0);
    glVertex2f(+1.64,-1.60);
    glVertex2f(+1.58,-1.60);
    glVertex2f(+1.61,-1.53);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.59,-1.60);
    glVertex2f(+1.55,-1.60);
    glVertex2f(+1.58,-1.50);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.56,-1.60);
    glVertex2f(+1.51,-1.60);
    glVertex2f(+1.54,-1.56);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-12
    glColor3ub(0,128,0);
    glVertex2f(+1.51,-1.30);
    glVertex2f(+1.45,-1.30);
    glVertex2f(+1.47,-1.23);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.46,-1.30);
    glVertex2f(+1.42,-1.30);
    glVertex2f(+1.47,-1.20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.45,-1.30);
    glVertex2f(+1.40,-1.30);
    glVertex2f(+1.43,-1.26);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-13
    glColor3ub(0,128,0);
    glVertex2f(+1.64,-1.30);
    glVertex2f(+1.58,-1.30);
    glVertex2f(+1.61,-1.23);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.59,-1.30);
    glVertex2f(+1.55,-1.30);
    glVertex2f(+1.58,-1.20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.56,-1.30);
    glVertex2f(+1.51,-1.30);
    glVertex2f(+1.54,-1.26);
    glEnd();

    glBegin(GL_TRIANGLES);   //Code for Grass-14
    glColor3ub(0,128,0);
    glVertex2f(+1.51,-1.30);
    glVertex2f(+1.45,-1.30);
    glVertex2f(+1.47,-1.23);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.46,-1.30);
    glVertex2f(+1.42,-1.30);
    glVertex2f(+1.47,-1.20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(+1.45,-1.30);
    glVertex2f(+1.40,-1.30);
    glVertex2f(+1.43,-1.26);
    glEnd();

    glLoadIdentity();

    if(count==3)
    {
        ballspeed+=0.0002;
        count=0;
    }

    if(ballY<-1.56 && (ballX>basketX-0.18 && ballX<basketX+0.18))
    {
       count++;
       point++;
       ballY=+1.80;
       r=rand()%5;
       if(r==0)
       {
           ballX=-1.80;
           tileX=-1.30;
       }
       if(r==1)
       {
           ballX=-1.40;
           tileX=-0.90;
       }
       if(r==2)
       {
           ballX=+1.00;
           tileX=+0.50;
       }
       if(r==3)
       {
           ballX=+1.40;
           tileX=+0.90;
       }
       if(r==4)
       {
           ballX=+1.80;
           tileX=+1.30;
       }
    }

    if(flagout==0)
    ballY-=0.0007+ballspeed;   //Speed of the Ball

    if(ballY<-1.75)
    {
       flagout=1;
    }

    if(flagout==1)
    {
       printf(" Game Over \n");
       printf(" Total Points Scored is %d \n",point);
       printf(" Thanks for Playing the Game \n");
       exit(1);
    }

    glPushMatrix();
    glTranslatef(ballX,ballY,0);
    ball();           //For Ball
    glPopMatrix();

    glPushMatrix();   //For Basket
    glTranslatef(basketX,basketY,0);
    glRotatef(90,1,0,0);  //Used to Rotate the Cone for FV to TV
    basket();
    glPopMatrix();

    glPushMatrix();    //For Tile
    glTranslatef(tileX,tileY,0);
    glScalef(1.5,0.35,1);
    tile();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void skeys(int key,int x,int y)
{
    if(key==GLUT_KEY_LEFT)
        basketX-=0.2;
    if(key==GLUT_KEY_RIGHT)
        basketX+=0.2;
    if(basketX<-2.0)
        basketX=basketX+0.30;   //To make Basket remain within the Screen
    if(basketX>+2.0)
        basketX=basketX-0.30;   //To make Basket remain within the Screen
}

int main(int c, char **v)   //Main Function
{
    glutInit(&c,v);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(575,50);
    glutCreateWindow("The Ball and Basket Game");
    init();
    glutDisplayFunc(draw);
    glutSpecialFunc(skeys);
    printf(" Welcome to The Ball and Basket Game \n\n");
    printf(" Press Left Arrow Key to Move the Basket Towards Left \n\n");
    printf(" Press Right Arrow Key to Move the Basket Towards Right \n\n");
    glutMainLoop();
    return 0;
}
