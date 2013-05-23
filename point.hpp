#ifndef DEF_POINT
#define DEF_POINT

#include <cmath>
#include <iostream>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "calc.hpp"

class Point{

public:
	Point(float x, float y, float z);
	Point();
	float getX();
	float getY();
	float getZ();
	void comp(float u, float v);
	void super_comp(float u, float v, float ea, float eb);
	void para_comp(float u, float v, float ea, float eb);
	void blend_comp(float u, float v,float alpha, float ea, float eb);

	void blend_comp_dual(float u, float v,float alpha, float ea, float eb, float ec, float ed);
	void show();

private:
	float x;
	float y;
	float z;

};
#endif