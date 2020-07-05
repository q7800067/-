#include<iostream>
#include<string>
#include <vector>
#include<functional>
#include <algorithm>

using namespace std;
class Transform {
public:
	int operator()(int val) {
		return val;
	}
};
class myprint {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};
void test() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	
	vector<int>vtarget;
	vtarget.resize(v.size());
	transform(v.begin(), v.end(), vtarget.begin(), Transform());
	for_each(vtarget.begin(), vtarget.end(),myprint());
}


int main() {
	test();
}





















