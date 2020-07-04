#include<iostream>
#include<string>
#include<deque>
#include<map>
#include <ctime>
#include<vector>

using namespace std;
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
class worker {
public:
	string m_name;
	int m_salary;
};

void createworker(vector<worker>& v) {
	string nameseed = "abcdefghij";
	for (int i = 0; i < 10; i++) {
		worker worker;
		worker.m_name = "员工";
		worker.m_name += nameseed[i];
		worker.m_salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}
void setgroup(vector<worker>& v,multimap<int ,worker>&m) {
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptid = rand() % 3;
		m.insert(make_pair(deptid, *it));
	}
}
void showgroup(multimap<int,worker>&m) {
	cout << "--------------------策划部门-----------------" << endl;;
	m.find(CEHUA);
	multimap<int, worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end()&&index<count; pos++,index++) {
		cout << "姓名" << pos->second.m_name << "工资" << pos->second.m_salary <<endl;
	}
	cout << "--------------------美术部--------------------" << endl;;
	
	/*multimap<int, worker>::iterator pos = m.find(MEISHU);*/
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	 index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "姓名" << pos->second.m_name << "工资" << pos->second.m_salary << endl;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	vector<worker>vworker;
	createworker(vworker);

	multimap<int, worker>mworker;
	setgroup(vworker, mworker);
		
	showgroup(mworker);
	//for (vector<worker>::iterator it = vworker.begin(); it != vworker.end(); it++)
	//{
	//	cout << "姓名" << it->m_name << "工资" << it->m_salary << endl;
	//}
}