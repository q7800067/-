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

//测试内置数据类型
void test01()
{
	myarray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.push_back(i);
	}
	cout << "array1打印输出：" << endl;
	printintarray(array1);
	cout << "array1的大小：" << array1.getsize() << endl;
	cout << "array1的容量：" << array1.getcapacity() << endl;
	cout << "--------------------------" << endl;

	myarray<int> array2(array1);
	array2.pop_back();
	cout << "array2打印输出：" << endl;
	printintarray(array2);
	cout << "array2的大小：" << array2.getsize() << endl;
	cout << "array2的容量：" << array2.getcapacity() << endl;
}

//测试自定义数据类型
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
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}

}

void test02()
{
	//创建数组
	myarray<person> parray(10);
	person p1("孙悟空", 30);
	person p2("韩信", 20);
	person p3("妲己", 18);
	person p4("王昭君", 15);
	person p5("赵云", 24);

	//插入数据
	parray.push_back(p1);
	parray.push_back(p2);
	parray.push_back(p3);
	parray.push_back(p4);
	parray.push_back(p5);

	printpersonarray(parray);

	cout << "pArray的大小：" << parray.getsize() << endl;
	cout << "pArray的容量：" << parray.getcapacity() << endl;

}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}