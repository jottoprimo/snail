#include "resource.h"
#include "primetives.h"

class Coord{
public:
	union {
		float coord[3];
		float x,y,z;
	}
};

class Model{
public:
	std::vector<Coord> coords;
	std::vector<Triangle> triangles;
};