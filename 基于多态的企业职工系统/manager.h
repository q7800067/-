#pragma once 
#include<iostream>
using namespace std;
#include "worker.h"

//Ա����
class manager :public worker
{
public:

	//���캯��
	manager(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void showinfo();

	//��ȡְ����λ����
	virtual string getdeptname();
};