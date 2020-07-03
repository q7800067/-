#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printvector(vector<int>v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test() {
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	printvector(v1); \
		v1.pop_back();
	printvector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printvector(v1);

	v1.erase(v1.begin());
	printvector(v1);
}

int main() {
	test();
}