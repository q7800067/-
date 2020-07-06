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
	if (this->m_fileisempty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入想要删除职工编号" << endl;
		int id = 0;
		cin >> id;
		int index=this->isexist(id);
		if (index != -1) { //找到了
			for (int i = index; i < this->m_empnum-1; i++) {
				this->m_emparray[i] = this->m_emparray[i + 1]; //数据前移
			}
			this->m_empnum--;//更新数组中记录人员个数
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改员工
void workermanager::mod_emp() {
	if (this->m_fileisempty) {
		cout << "文件不存在" << endl;
	}
	else {
		cout << "请输入修改职工编号" << endl;
		int id;
		cin >> id;
		int ret=this->isexist(id);
		if (ret != -1) {
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = " ";
			int dselect = 0;
			cout << "查到：" << id << "号职工，请输入新职工号" << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入岗位" << endl;
			cin >> dselect;
			worker* worker = NULL;
			switch (dselect) {
			case 1:
				worker = new employee(newid, newname, dselect);
			case 2:
				worker = new manager(newid, newname, dselect);
			case 3:
				worker = new boss(newid, newname, dselect);
			default:
				break;
			}
			this->m_emparray[ret] = worker;  //更改数据到数组中
			cout << "修改成功" << this->m_emparray[ret]->m_deptid<<endl;
			this->save();
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workermanager::find_emp() {
	if (this->m_fileisempty) {
		cout << "文件不存在" << endl;
		}
	else {
		cout << "请输入查找方式" << endl;
		cout << "按1职工编号查找" << endl;
		cout << "按2职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "请输入查找的职工编号" << endl;
			cin >> id;
			int ret = isexist(id);
			if (ret != -1) {
				cout << "查找成功" << endl;
				this->m_emparray[ret]->showinfo();
			}
			else {
				cout << "查找失败" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "请输入姓名" << endl;
			cin >> name;
			bool flag = false; //默认未找到职工
			for (int i = 0; i < m_empnum; i++) {
				if (this->m_emparray[i]->m_name == name) {
					cout << "查找成功，职工编号为=" << this->m_emparray[i]->m_id
						<< "号职工信息如下"<< endl;
					flag = true;
					this->m_emparray[i]->showinfo();
				}
			}
			if (flag == false) {
				cout << "查无此人" << endl;
			}
		}
		else {
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workermanager::sort_emp() {
	if (this->m_fileisempty) {
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empnum; i++) {
			int minormax = i;
			for(int j=i+1;j<this->m_empnum;j++){
				if (select == 1) {
					if (this->m_emparray[minormax]->m_id > this->m_emparray[j]->m_id) {
						minormax = j;
					}
				}
				else {
					if (this->m_emparray[minormax]->m_id < this->m_emparray[j]->m_id) {
						minormax = j;
					}
				}
			}
			if (i != minormax) {
				worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[minormax];
				this->m_emparray[minormax] = temp;
			}
		}
		cout << "排序成功！排序后的结果为：" << endl;
		this->save();
		this->showemp();


	}
}

void workermanager::clean_file() {
	cout << "确定清空？" << endl;
	cout << "1确定" << endl;
	cout << "2返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;
			}
			delete[]this->m_emparray;  //删除堆区数组指针
			this->m_emparray = NULL;
			this->m_empnum = 0;
			this->m_fileisempty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}