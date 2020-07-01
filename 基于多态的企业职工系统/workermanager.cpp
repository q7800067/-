#include"workermanager.h"

void workermanager::exitsystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workermanager::showmenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
workermanager::workermanager() {
	this->m_empnum = 0;
	this->m_emparray = NULL;
}

void workermanager::addemp() {
	cout << "请输入添加职工数量" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) 
	{
		int newsize = this->m_empnum + addnum;//计算新空间大小
		worker** newspace = new worker * [newsize];//开辟新空间
		if (this->m_emparray != NULL)
		{ //将原空间下内容放到新空间下
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
		}
			for (int i = 0; i < addnum; i++) { //输入新数据
				int id;
				string name;
				int dselect;
				cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
				cin >> id;
				cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
				cin >> name;
				cout << "请选择该职工岗位：" << endl;
				cout << "1普通职工" << endl;
				cout << "2经理" << endl;
				cout << "3老板" << endl;
				cin >> dselect;
				worker* a = NULL;
				switch (dselect) {
				case 1:
					a = new employee(id, name, 1);
					break;
				case 2:
					a = new manager(id, name, 2);
					break;
				case 3:
					a = new boss(id, name, 3);
					break;
				default:
					break;
				}
				newspace[this->m_empnum + i] = a;
			}
			delete[] this->m_emparray;  //释放原有空间
			this->m_emparray = newspace;//更改新空间的指向
			this->m_empnum = newsize;//更新新的个数
			cout << "成功添加了" << addnum << "名新员工" << endl;
	
	}
	else
	{
			cout << "输入有误，请重新输入" << endl;
	}
		system("pause");
		system("cls");
	}





workermanager::~workermanager()  //不添加这段代码就会出错
{
	if (this->m_emparray!=NULL)
	{
		delete[] this->m_emparray;
	}
}