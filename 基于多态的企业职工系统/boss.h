#pragma once 
#include<iostream>
using namespace std;
#include "worker.h"

//Ա����
class boss :public worker
{
public:

	//���캯��
	boss(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void showinfo();

	//��ȡְ����λ����
	virtual string getdeptname();
};