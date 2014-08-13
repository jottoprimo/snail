#include "vector.h"

float Vector2::length(){
	return sqrtf(x*x+y*y);
}

void Vector2::normalize(){
	float len=length();
	x/=len;
	y/=len;
}

float Vector3::length(){
	return sqrtf(x*x+y*y+z*z);
}

void Vector3::normalize(){
	float len=length();
	x/=len;
	y/=len;
	z/=len;
}

float Vector4::length(){
	return(sqrtf(x*x+y*y+z*z));
}

void Vector4::normalize(){
	float len=length();
	x/=x;
	y/=y;
	z/=z;
}
