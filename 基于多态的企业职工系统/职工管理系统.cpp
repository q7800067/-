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
			wm.showemp();
			break;
		case 3: //ɾ��ְ��
		/*{int ret = wm.isexist(1);
		if (ret != -1) {
			cout << "ְ������" << endl;
		}
		else {
			cout << "ְ��������" << endl;
		}*/
			wm.del_emp();
		break; 
		case 4: //�޸�ְ��
			wm.mod_emp();
			break;
		case 5: //����ְ��
			wm.find_emp();
			break;
		case 6: //����ְ��
			wm.sort_emp();
			break;
		case 7: //����ļ�
			wm.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}