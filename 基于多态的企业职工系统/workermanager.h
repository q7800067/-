#include <iostream>
#include<string>
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empfile.txt"


using namespace std;
class workermanager {
public:
	void exitsystem();
	void showmenu();
	int m_empnum;//记录文件汇总的人数个数
	worker** m_emparray; //员工数组指针
	void addemp();
	void save();
	bool m_fileisempty;
	int get_empnum(); //统计文件中的人数
	void init_emp();
	void showemp(); //显示员工
	void  del_emp();  //删除员工
	int isexist(int id);
	//构造函数
	workermanager();
	//析构函数
	~workermanager();
};
