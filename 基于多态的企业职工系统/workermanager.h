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
	int m_empnum;//��¼�ļ����ܵ���������
	worker** m_emparray; //Ա������ָ��
	void addemp();
	void save();
	bool m_fileisempty;
	int get_empnum(); //ͳ���ļ��е�����
	void init_emp();
	void showemp(); //��ʾԱ��
	void  del_emp();  //ɾ��Ա��
	int isexist(int id);
	//���캯��
	workermanager();
	//��������
	~workermanager();
};
