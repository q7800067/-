#pragma once             
#include<string>
#include<iostream>
using namespace std;

template <class T>
class myarray {
public:
	//有参构造
	myarray(int capacity) {
		this->m_capacity = capacity;
		this->m_size = 0;
		this->paddress = new T[this->m_capacity];
	}

	//拷贝构造
	myarray(const myarray& arr) {
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->paddress = new T[arr.m_capacity];
			for (int i = 0; i < this->m_size; i++) {
				this->paddress[i] = arr.paddress[i];
			}
	}
	//---------------
	myarray& operator=(const myarray& myarray) {
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
	T& operator[](int index) {
		return this->paddress[index];
	}
	//尾插法
	void push_back(const T& val) {
		if(this->m_capacity == this->m_size) {
			return;
		}
		this->paddress[this->m_size] = val;
		this->m_size++;
	}
	//尾删法
	void pop_back()
	{
		if (this->m_size == 0)
		{return;}
		this->m_size--;
	}
	//获取数组容量
	int getcapacity()
	{
		return this->m_capacity;
	}

	//获取数组大小
	int	getsize()
	{
		return this->m_size;
	}
	~myarray() {
		if (this->paddress != NULL)
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
	int m_size;
};

