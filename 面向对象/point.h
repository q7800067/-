#pragma once
using namespace std;
#include<iostream>
#include<string >

class point {
public:
	void setx(int x);
	int getx();
	void sety(int y);
	int gety();
private:int m_x; int m_y;
};