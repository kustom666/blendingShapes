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

void Point::para_comp(float u, float v, float ea, float eb)
{
	float p = pow((pow((pow((fabs(cos(u)*cos(v))),(2/eb)) + pow((fabs(sin(u)*cos(v))),(2/eb))), (eb/ea)) + pow((fabs(sin(v))), 2/ea)), -(ea/2));
	//p = [{(|cos(w)*cos(n)|^(2/e2)) + (|sin(w) * cos(n)|^(2/e2))}^(e2/e1) + |sin n|^(2/e1)]^(-e1/2)
	this->x = p * aux_c(v, ea) * aux_c(u, eb);
    this->y = p * aux_c(v, ea) * aux_s(u, eb);
    this->z = p * aux_s(v, ea);
}

void Point::blend_comp(float u, float v, float alpha, float ea, float eb)
{

	this->x = cos(v)*cos(u)*blend(alpha) + aux_c(v, ea) * aux_c(u, eb) * (1-blend(alpha));
	this->y = cos(v)*sin(u)*blend(alpha) + aux_c(v, ea) * aux_s(u, eb) * (1-blend(alpha));
	this->z = sin(v)*blend(alpha) + aux_s(v, ea) * (1-blend(alpha));
}

void Point::blend_comp_dual(float u, float v,float alpha, float ea, float eb, float ec, float ed)
{

	this->x = aux_c(v, ea) * aux_c(u, eb)*blend(alpha) + aux_c(v, ec) * aux_c(u, ed) * (1-blend(alpha));
	this->y = aux_c(v, ea) * aux_s(u, eb) + aux_c(v, ec) * aux_s(u, ed) * (1-blend(alpha));
	this->z = aux_s(v, ea)*blend(alpha) + aux_s(v, ec) * (1-blend(alpha));
}

