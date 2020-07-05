using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
void test() {
	vector<int>v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	int total=accumulate(v.begin(), v.end(), 5);
	cout << total << endl;
}
int main() {
	test();
}






















