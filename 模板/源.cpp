#include <iostream>
using namespace std;

template<class T>
bool mycompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}