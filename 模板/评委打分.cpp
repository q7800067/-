#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#include<vector>
#include<deque>
#include "time.h"
class person {
public:
	person(string name, int score) {
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};

void createperson(vector<person>& v) {
	string nameseed = "abcde";
	for (int i = 0; i < 5; i++) {
		string name = "ѡ��";
		name += nameseed[i];
		int score = 0;
		person p(name, score);
	}
}
void setscore(vector<person>& v) {
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;  //60~100
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();  //ȥ�������ͷ�
		d.pop_front();
		int sum = 0;  //ȡƽ����
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		it->m_score = avg;
	}
}
void showscore(vector<person>& v) {
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "����" << it->m_name << "ƽ����="<<it->m_score<<endl;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	vector<person>v;
	createperson(v);
	setscore(v);
	showscore(v);
}