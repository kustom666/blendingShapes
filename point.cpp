#include "point.hpp"
Point::Point(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Point::Point()
{
}

float Point::getX()
{
	return this->x;
}

float Point::getY()
{
	return this->y;
}

float Point::getZ()
{
	return this->z;
}

void Point::comp(float u, float v)
{
	this->x = cos(v)*cos(u);
    this->y = cos(v)*sin(u);
    this->z = sin(v);
}

void Point::super_comp(float u, float v, float ea, float eb)
{
	this->x = aux_c(v, ea) * aux_c(u, eb);
    this->y = aux_c(v, ea) * aux_s(u, eb);
    this->z = aux_s(v, ea);
}

void Point::show()
{
	glBegin(GL_POINTS);
		glVertex3f(this->x, this->y, this->z);
	glEnd();
}