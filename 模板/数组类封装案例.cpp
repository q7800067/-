#include "myarray.hpp"
#include <string>
#include<iostream>
using namespace std;

void printintarray(myarray<int>& arr) {
	for (int i = 0; i < arr.getsize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//����������������
void test01()
{
	myarray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.push_back(i);
	}
	cout << "array1��ӡ�����" << endl;
	printintarray(array1);
	cout << "array1�Ĵ�С��" << array1.getsize() << endl;
	cout << "array1��������" << array1.getcapacity() << endl;
	cout << "--------------------------" << endl;

	myarray<int> array2(array1);
	array2.pop_back();
	cout << "array2��ӡ�����" << endl;
	printintarray(array2);
	cout << "array2�Ĵ�С��" << array2.getsize() << endl;
	cout << "array2��������" << array2.getcapacity() << endl;
}

//�����Զ�����������
class person {
public:
	person() {}
	person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printpersonarray(myarray<person>& personArr)
{
	for (int i = 0; i < personArr.getsize(); i++) {
		cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << endl;
	}

}

void test02()
{
	//��������
	myarray<person> parray(10);
	person p1("�����", 30);
	person p2("����", 20);
	person p3("槼�", 18);
	person p4("���Ѿ�", 15);
	person p5("����", 24);

	//��������
	parray.push_back(p1);
	parray.push_back(p2);
	parray.push_back(p3);
	parray.push_back(p4);
	parray.push_back(p5);

	printpersonarray(parray);

	cout << "pArray�Ĵ�С��" << parray.getsize() << endl;
	cout << "pArray��������" << parray.getcapacity() << endl;

}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}