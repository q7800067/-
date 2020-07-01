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
		worker* worker = NULL;
		worker = new employee(1, "张三", 1);
		worker->showinfo();
		delete worker;

		worker = new manager(2, "李四", 2);
		worker->showinfo();
		delete worker;

		worker = new boss(3, "王五", 3);
		worker->showinfo();
		delete worker;



		//展示菜单
		wm.showmenu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.exitsystem();
			break;
		case 1: //添加职工
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}