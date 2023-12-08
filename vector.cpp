#pragma once
#include <iostream>

class Vector2D{
public:
    float x, y;
    Vector2D(){x = 0; y = 0;}

	Vector2D(float p_x, float p_y):x(p_x), y(p_y){}


	//maarij homo

	void print(){
		std::cout << x << ", " << y << std::endl;
	}
};