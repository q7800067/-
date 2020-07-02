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
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//2文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//文件存在，并且记录数据
	int num = this->get_empnum();
	/*cout << "职工人数为" << num << endl;*/
	this->m_empnum = num;

	this->m_emparray = new worker * [this->m_empnum];//开辟空间
	this->init_emp(); //将文件中的数据，存到数组中
	////测试代码
	//for (int i = 0; i < this->m_empnum; i++) {
	//	cout << "职工编号" << this->m_emparray[i]->m_id
	//		<< "姓名" << this->m_emparray[i]->m_name
	//		<< "部门编号" << this->m_emparray[i]->m_deptid << endl;
	//}

	this->m_empnum = 0;
	this->m_emparray = NULL;
}
//第154集
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
			this->m_fileisempty = false;  //更新员工不为空标志
			cout << "成功添加了" << addnum << "名新员工" << endl;
			this->save();
	}
	else
	{
			cout << "输入有误，请重新输入" << endl;
	}
		system("pause");
		system("cls");
	}

int workermanager::get_empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id&& ifs >> name && ifs >> did) {
		num++;
	}
	return num;
}

void workermanager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		worker* worker = NULL;
		if (did == 1) {
			worker = new employee(id, name, did);
		}
		else if (did == 2) {
			worker = new manager(id, name, did);
		}
		else {
			worker = new boss(id, name, did);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}

workermanager::~workermanager()  //不添加这段代码就会出错
{
	if (this->m_emparray!=NULL)
	{
		delete[] this->m_emparray;
	}
}

void workermanager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_empnum; i++) {
		ofs << this->m_emparray[i]->m_id << "  "
			<< this->m_emparray[i]->m_name << "  "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	ofs.close();
}
//显示员工
void workermanager::showemp() {
	if (this->m_fileisempty) {
		cout << "文件不存在" << endl;
	}
	else {
		for (int i = 0; i < m_empnum; i++) {
			this->m_emparray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
int workermanager::isexist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++) {
		if (this->m_emparray[i]->m_id == id) {
			index = i;
			break;
		}
	}
	return index;
}
//删除职工
void  workermanager::del_emp() {

}