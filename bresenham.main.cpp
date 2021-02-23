#include <GL/glut.h> 
#include<math.h>
#include<iostream>
using namespace std;
void Cirpot(int x0,int y0,float x,float y)
{
	glBegin(GL_POINTS);
	glColor3f(1,0,0); 
	glVertex2f((x0+x)/1000,(y0+y)/1000);
	glVertex2f((x0+y)/1000,(y0+x)/1000);
	glVertex2f((x0+y)/1000,(y0-x)/1000);
	glVertex2f((x0+x)/1000,(y0-y)/1000);	
	glVertex2f((x0-x)/1000,(y0-y)/1000);
	glVertex2f((x0-y)/1000,(y0-x)/1000);
	glVertex2f((x0-y)/1000,(y0+x)/1000);
	glVertex2f((x0-x)/1000,(y0+y)/1000);
	glEnd();
}

void Bresenham(float x0,float y0,float r)
{
	float d,x,y;
	x=0;
	y=r;
	d=3-2*r;
	while(x<=y){
		Cirpot(x0,y0,x,y);
		if(d<0)
			d+=4*x+6;
		else{
			d+=4*(x-y)+10;
			y--;
		}
		x++;
	}
}
  

void display(void){
 float x0,y0,r;
 cout<<"Please enter the dot coordinates and radius:"<<endl;
 cin>>x0>>y0>>r;
 Bresenham(x0,y0,r);
 glFlush(); 
}

int main(int argc, char **argv) { 
     glutInit(&argc, argv); //Initialize glut
  glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA); 
       //Set the mode of the window-depth buffer, single buffer, color model
     glutInitWindowPosition(200,200); //Set the position of the window
     glutInitWindowSize(400,400); //Set the size of the window
     glutCreateWindow("3D Tech- GLUT Tutorial"); //Create window and assign title
     glutDisplayFunc(display);//Call display to transfer the drawing to the window. The prototype of this function is glutDisplayFunc(void)
     glutMainLoop(); //Enter the loop and wait
}


