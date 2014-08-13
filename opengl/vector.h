#include "primetives.h"
#include "resource.h"

class Vector2{
public:
	union {
		float coord[2];
		float x,y;
	};
	Vector2(float x, float y):x(x), y(y){};
	Vector2():x(0.f),y(0.f){};

	void normalize();
	float length();
};

class Vector3{
public:
	union {
		float coord[3];
		float x,y,z;
	};
	Vector3(Vector2 vec):x(vec.x),y(vec.y),z(0.f){};
	Vector3(float x, float y, float z):x(x), y(y), z(z){};
	Vector3():x(0.f),y(0.f), z(0.f){};

	void normalize();
	float length();
};

class Vector4{
public:
	union {
		float coord[4];
		float x,y,z,w;
	};
	Vector4(Vector2 vec):x(vec.x),y(vec.y),z(0.f),w(1.f){};
	Vector4(Vector3 vec):x(vec.x),y(vec.y),z(vec.z),w(1.f){};
	Vector4(float x, float y, float z, float w):x(x), y(y), z(z), w(w){};
	Vector4():x(0.f),y(0.f),z(0.f),w(0.f){};

	void normalize();
	float length();
};