#include "resource.h"
#include "primetives.h"

void Box::draw(){
	glColor4fv(color.colors);
	//� ���
	glVertex3f(-x,  y, z);
	glVertex3f(-x, -y, z);
	glVertex3f( x,  y, z);

	glVertex3f( x,  y, z);
	glVertex3f(-x, -y, z);
	glVertex3f( x, -y, z);
		
		
	//������
	glVertex3f( x, -y,  z);
	glVertex3f( x, -y, -z);
	glVertex3f( x,  y, -z);

	glVertex3f( x,  y, -z);
	glVertex3f( x,  y,  z);
	glVertex3f( x, -y,  z);

	//������
	glVertex3f( x, -y,  z);
	glVertex3f( x, -y, -z);
	glVertex3f(-x, -y, -z);

	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y,  z);
	glVertex3f( x, -y,  z);

	//�������
	glVertex3f(-x,  y,  z);
	glVertex3f(-x,  y, -z);
	glVertex3f( x,  y,  z);

	glVertex3f( x,  y,  z);
	glVertex3f(-x,  y, -z);
	glVertex3f( x,  y, -z);

	//�� ���
	glVertex3f(-x,  y,  z);
	glVertex3f(-x, -y,  z);
	glVertex3f( x,  y,  z);

	glVertex3f( x,  y,  z);
	glVertex3f(-x, -y,  z);
	glVertex3f( x, -y,  z);
		

	//�����
	glVertex3f(-x,  y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x,  y,  z);

	glVertex3f(-x,  y,  z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y,  z);
}

void drawBox(){
	//� ���
	glVertex3f(-0.5,  0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f( 0.5,  0.5, 0.5);

	glVertex3f( 0.5,  0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f( 0.5, -0.5, 0.5);
		
		
	//������
	glVertex3f( 0.5, -0.5,  0.5);
	glVertex3f( 0.5, -0.5, -0.5);
	glVertex3f( 0.5,  0.5, -0.5);

	glVertex3f( 0.5,  0.5, -0.5);
	glVertex3f( 0.5,  0.5,  0.5);
	glVertex3f( 0.5, -0.5,  0.5);

	//������
	glVertex3f( 0.5, -0.5,  0.5);
	glVertex3f( 0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5,  0.5);
	glVertex3f( 0.5, -0.5,  0.5);

	//�������
	glVertex3f(-0.5,  0.5,  0.5);
	glVertex3f(-0.5,  0.5, -0.5);
	glVertex3f( 0.5,  0.5,  0.5);

	glVertex3f( 0.5,  0.5,  0.5);
	glVertex3f(-0.5,  0.5, -0.5);
	glVertex3f( 0.5,  0.5, -0.5);

	//�� ���
	glVertex3f(-0.5,  0.5,  0.5);
	glVertex3f(-0.5, -0.5,  0.5);
	glVertex3f( 0.5,  0.5,  0.5);

	glVertex3f( 0.5,  0.5,  0.5);
	glVertex3f(-0.5, -0.5,  0.5);
	glVertex3f( 0.5, -0.5,  0.5);
		

	//�����
	glVertex3f(-0.5,  0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5,  0.5,  0.5);

	glVertex3f(-0.5,  0.5,  0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5,  0.5);
}