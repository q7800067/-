#include<iostream>
#include<string>
using namespace std;
#include<vector>
void printvector(vector<int>v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test() {
	vector <int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printvector(v1);
	vector<int>v2;
	for (int i = 0; i > 0; i--) {
		v2.push_back(i);
	}
	printvector(v2);

	v1.swap(v2);
	printvector(v1);
}


int main() {
	test();
}