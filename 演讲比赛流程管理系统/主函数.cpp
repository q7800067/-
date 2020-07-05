#include<iostream>
#include<string>
using namespace std;
#include "speechmanager.h"

int main() {
	speechmanager sm;	
	////测试是否已经创建,要注意怎么调用的姓名...value是一个对象，里面有两个成员属性
	for (map<int, speaker>::iterator it = sm.m_speaker.begin(); it!=sm.m_speaker.end(); it++) {
		cout << "选手编号=" << it->first << "\t姓名=" << it->second.m_name << "\t分数=" << it->second.m_score << endl;
	}
	cout << "请输入您的选项" << endl;
	int choice = 0;	
	while (true) {
		sm.showmenu();
		cin >> choice;
		switch (choice) 
		{
		case 1:sm.startspeech();
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			sm.exitsystem();
			break;
		default:
			system("cls");
			break;

		}
	}

}
