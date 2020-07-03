#pragma once             
#include<string>
#include<iostream>
using namespace std;

template <class T>
class myarray {
public:
	//�вι���
	myarray(int capacity) {
		this->m_capacity = capacity;
		this->m_size = 0;
		this->paddress = new T[this->m_capacity];
	}

	//��������
	myarray(const myarray& arr) {
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->paddress=new T[arr.m_capacity]
			for (int i = 0; i < this->m_size; i++) {
				this->paddress[i] = arr.paddress[i];
			}
	}
	//---------------
	myarray& operator=(const myarray& arr) {
		if (this->paddress != NULL) {
			delete[] this->paddress;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = myarray.m_capacity;
		this->m_size = myarray.m_size;
		this->paddress = new T[this->m_capacity];
		for (int i = 0; i < this->m_size; i++) {
			this->paddress[i] = myarray[i];
		}
		return *this;
	}
	T& oprtator[](int index) {
		return this->paddress[index];
	}
	//β�巨
	void push_back(const T& val) {
		if(this->m_capacity == this->m_size) {
			return;
		}
		this->paddress[this->m_size] = val;
		this->m_size++;
	}
	//βɾ��
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//��ȡ��������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��ȡ�����С
	int	getSize()
	{
		return this->m_Size;
	}
	~myarray() {
		if (this->pAddress != NULL)
		{
			delete[] this->paddress;
			this->paddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
	}
private:
	T* paddress;
	int m_capacity;
};

