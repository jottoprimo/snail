#include "resource.h"

class Color4{
public:
	union {
		struct { float colors[4]; };
		struct { float r,g,b,a; };
	};
	Color4(float r, float g, float b, float a):r(r), g(g), b(b), a(a){};
	Color4():r(0.f), g(0.f), b(0.f), a(1.f){};
};

class Box{
public:
	Color4 color;
	float x,y,z;
	Box(float x, float y, float z, Color4 color):x(x), y(y), z(z), color(color){};
	void draw();
};

void drawBox();