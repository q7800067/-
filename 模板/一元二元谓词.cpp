using namespace std;
#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
class greaterfive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void test01() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//greaterfive��������������
	vector <int>::iterator it=find_if(v.begin(), v.end(), greaterfive());
	if (it == v.end()) {
		cout << "δ�ҵ�" <<endl;
	}
	else {
		cout << "�ҵ��˴���5������" <<*it<< endl;
	}
}
//-------------------��Ԫν��--------------------------
class mycompare {
public:
	bool operator()(int val1, int val2) {
		return val1 > val2;
	}
};
void test02() {
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	sort(v.begin(), v.end(), mycompare());
	cout << "-----------�仯��---------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
}
int main() {
	test01();
	test02();
}









