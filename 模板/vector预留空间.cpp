#include<iostream>
#include<string>
using namespace std;
#include<vector>
void test() {
	vector<int>v;
	v.reserve(100000);
	int num = 0;//统计开辟次数
	int* p = NULL;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{ 
			p = &v[0];
			num++;
		}
	}
	cout << "num=" << num << endl;
}



int main() {
	test();
}