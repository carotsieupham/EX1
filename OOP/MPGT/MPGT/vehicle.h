#pragma once
#include <iostream>

#include <random>
#include <fstream>
#include <string>
using namespace std;
class vehicle
{
private:
	float x,v;
	
public:
	vehicle(float vtri=0.0, float vtoc=0.0);
	float capNhapVitri(float dt);
	float dieuChinhTocDo();
	float getposition();
	float getspeed();
	
};

