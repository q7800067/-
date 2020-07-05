#include<iostream>
#include<string>
#include<deque>
#include<set>
using namespace std;

void test() {
	set<int>s;
	pair<set<int>::iterator, bool>ret = s.insert(10);  //看一下
	if (ret.second) {
		cout << "第一次插入成功" << endl;
	}
	else {
		cout << "第二次插入失败" << endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		cout << "第一次插入成功" << endl;
	}
	else {
		cout << "第二次插入失败" << endl;
	}
	//multiset
	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}



int main() {
	test();
}