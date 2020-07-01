#include <iostream>
#include<string>
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
using namespace std;
class workermanager {
public:
	void exitsystem();
	void showmenu();
	int m_empnum;//记录文件汇总的人数个数
	worker** m_emparray; //员工数组指针
	void addemp();




	//构造函数
	workermanager();
	//析构函数
	~workermanager();
};
