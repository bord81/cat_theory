#include "sum_type.h"
#include <cmath>

Circle::Circle(float r) : _radius(r) {}

Rect::Rect(double w, double h) : _width(w), _height(h) {}

Square::Square(double s) : _side(s) {}

double Circle::area() const { return M_PI * _radius * _radius; }

double Rect::area() const { return _width * _height; }

double Square::area() const { return _side * _side; }

double Circle::circ() const { return 2.0 * M_PI * _radius; }

double Rect::circ() const { return 2.0 * _width * _height; }

double Square::circ() const { return 4.0 * _side; }
