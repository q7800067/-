#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printvector(vector<int>v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
}
void test() {
	vector<int>v1;
	for (int i; i < 10; i++) {
		v1.push_back(i);
	}
	printvector(v1);
	if (v1.empty()) {
		cout << "v1Ϊ��" << endl;
	}
	else {
		cout << "v1������Ϊ" << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ" << v1.size() << endl;
	}
	v1.resize(15);
	printvector(v1);
}

int main() {

}