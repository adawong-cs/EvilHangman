#include "Rectangle.h"

//constructor
Rectangle::Rectangle() 
{
	width = 1;
	height = 1;
}

Rectangle::Rectangle(int w, int h)
{
	width = w;
	height = h;
}

//methods
int Rectangle::Area() const
{
	return width * height;
}

int Rectangle::Perimeter() const
{
	return width + width + height + height;
}

