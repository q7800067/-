#include<iostream>
#include<string>
using namespace std;
#include "speechmanager.h"

int main() {
	speechmanager sm;	
	////�����Ƿ��Ѿ�����,Ҫע����ô���õ�����...value��һ������������������Ա����
	for (map<int, speaker>::iterator it = sm.m_speaker.begin(); it!=sm.m_speaker.end(); it++) {
		cout << "ѡ�ֱ��=" << it->first << "\t����=" << it->second.m_name << "\t����=" << it->second.m_score << endl;
	}
	cout << "����������ѡ��" << endl;
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
