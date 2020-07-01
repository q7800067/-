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
	int m_empnum;
	worker** m_emparray;
	void addemp();




	//构造函数
	workermanager();
	//析构函数
	~workermanager();
};
