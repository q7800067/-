#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int main() {
	map<int,int>v;
	v.insert(pair<int,int>(4, 1));
	map<int, int>::iterator pos = v.find(4);
	cout << pos->first << endl;
	cout << pos->second << endl;
	
}

