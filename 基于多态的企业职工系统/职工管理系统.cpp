#include <iostream>
#include<string>
using namespace std;
#include"workermanager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"



int main() {

	workermanager wm;
	int choice = 0;
	while (true)
	{
		//չʾ�˵�
		wm.showmenu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitsystem();
			break;
		case 1: //���ְ��
			wm.addemp();
			break;
		case 2: //��ʾְ��
			break;
		case 3: //ɾ��ְ��
			break;
		case 4: //�޸�ְ��
			break;
		case 5: //����ְ��
			break;
		case 6: //����ְ��
			break;
		case 7: //����ļ�
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}