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
			wm.addemp();
			break;
		case 2: //显示职工
			wm.showemp();
			break;
		case 3: //删除职工
		/*{int ret = wm.isexist(1);
		if (ret != -1) {
			cout << "职工存在" << endl;
		}
		else {
			cout << "职工不存在" << endl;
		}*/
			wm.del_emp();
		break; 
		case 4: //修改职工
			wm.mod_emp();
			break;
		case 5: //查找职工
			wm.find_emp();
			break;
		case 6: //排序职工
			wm.sort_emp();
			break;
		case 7: //清空文件
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