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
	int m_empnum;//��¼�ļ����ܵ���������
	worker** m_emparray; //Ա������ָ��
	void addemp();




	//���캯��
	workermanager();
	//��������
	~workermanager();
};
