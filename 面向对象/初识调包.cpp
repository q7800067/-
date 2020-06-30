#include <iostream>
#include <string >
#include "point.h"
#include "circle.h"
using namespace std;
//class point {
//public:
//	void setx(int x) {m_x = x;}
//	int getx() {return m_x;}
//	void sety(int y) {m_y = y;}
//	int gety() {return m_y;}
//private:int m_x;int m_y;};
//class circle {
//public:
//	void setr(int r) {
//		m_r = r;
//	}
//	int getr() {
//		return m_r;
//	}
//	void setcenter(point center) {
//		m_center = center;
//	}
//	point getcenter() {
//		return m_center;
//	}
//private:
//	int m_r;
//	point m_center;
//};
void isincircle(circle& c, point& p) {
	//计算两点之间的距离平方
	int distance = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
		(c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());
	//计算半径的平方
	int rdistance = c.getr() * c.getr();
	if (distance == rdistance) {
		cout << "点在圆上" << endl;
	}
	else if (distance > rdistance) {
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆内" << endl;
	}
}



int main() {

	circle c;
	c.setr(10);
	point center;
	center.setx(10);
	center.sety(0);
	c.setcenter(center);

	point p;
	p.setx(10);
	p.sety(11);
	isincircle(c, p);












}