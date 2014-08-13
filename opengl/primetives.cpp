#include "resource.h"
#include "primetives.h"

void Box::draw(){
	glColor4fv(color.colors);
	//к нам
	glVertex3f(-x,  y, z);
	glVertex3f(-x, -y, z);
	glVertex3f( x,  y, z);

	glVertex3f( x,  y, z);
	glVertex3f(-x, -y, z);
	glVertex3f( x, -y, z);
		
		
	//права€
	glVertex3f( x, -y,  z);
	glVertex3f( x, -y, -z);
	glVertex3f( x,  y, -z);

	glVertex3f( x,  y, -z);
	glVertex3f( x,  y,  z);
	glVertex3f( x, -y,  z);

	//нижн€€
	glVertex3f( x, -y,  z);
	glVertex3f( x, -y, -z);
	glVertex3f(-x, -y, -z);

	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y,  z);
	glVertex3f( x, -y,  z);

	//верхн€€
	glVertex3f(-x,  y,  z);
	glVertex3f(-x,  y, -z);
	glVertex3f( x,  y,  z);

	glVertex3f( x,  y,  z);
	glVertex3f(-x,  y, -z);
	glVertex3f( x,  y, -z);

	//от нас
	glVertex3f(-x,  y,  z);
	glVertex3f(-x, -y,  z);
	glVertex3f( x,  y,  z);

	glVertex3f( x,  y,  z);
	glVertex3f(-x, -y,  z);
	glVertex3f( x, -y,  z);
		

	//лева€
	glVertex3f(-x,  y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x,  y,  z);

	glVertex3f(-x,  y,  z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y,  z);
}

void drawBox(){
	//к нам
	glVertex3f(-0.5,  0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f( 0.5,  0.5, 0.5);

	glVertex3f( 0.5,  0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f( 0.5, -0.5, 0.5);
		
		
	//права€
	glVertex3f( 0.5, -0.5,  0.5);
	glVertex3f( 0.5, -0.5, -0.5);
	glVertex3f( 0.5,  0.5, -0.5);

	glVertex3f( 0.5,  0.5, -0.5);
	glVertex3f( 0.5,  0.5,  0.5);
	glVertex3f( 0.5, -0.5,  0.5);

	//нижн€€
	glVertex3f( 0.5, -0.5,  0.5);
	glVertex3f( 0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5,  0.5);
	glVertex3f( 0.5, -0.5,  0.5);

	//верхн€€
	glVertex3f(-0.5,  0.5,  0.5);
	glVertex3f(-0.5,  0.5, -0.5);
	glVertex3f( 0.5,  0.5,  0.5);

	glVertex3f( 0.5,  0.5,  0.5);
	glVertex3f(-0.5,  0.5, -0.5);
	glVertex3f( 0.5,  0.5, -0.5);

	//от нас
	glVertex3f(-0.5,  0.5,  0.5);
	glVertex3f(-0.5, -0.5,  0.5);
	glVertex3f( 0.5,  0.5,  0.5);

	glVertex3f( 0.5,  0.5,  0.5);
	glVertex3f(-0.5, -0.5,  0.5);
	glVertex3f( 0.5, -0.5,  0.5);
		

	//лева€
	glVertex3f(-0.5,  0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5,  0.5,  0.5);

	glVertex3f(-0.5,  0.5,  0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5,  0.5);
}