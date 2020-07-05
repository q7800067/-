#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include<algorithm>
void myprint(int val) {
	cout << val << " ";
}
void test() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int>vtarget;
	vtarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myprint);
	cout << endl;
}

int main() {
	test();
}



















