#include <iostream>
#include <string >
using namespace std;
class Building;
class goodgay
{
public:
	goodgay();
	void visit();
	void visit2();
private:
	Building* building;
};


class Building
{
	//告诉编译器  goodgay类中的visit成员函数 是Building好朋友，可以访问私有内容
	friend void goodgay::visit();

public:
	Building();

public:
	string m_sittingroom; //客厅
private:
	string m_bedroom;//卧室
};

Building::Building()
{
	this->m_sittingroom = "客厅";
	this->m_bedroom = "卧室";
}

goodgay::goodgay()
{
	building = new Building;
}

void goodgay::visit()
{
	cout << "好基友正在访问" << building->m_sittingroom << endl;
	cout << "好基友正在访问" << building->m_bedroom << endl;
}

void goodgay::visit2()
{
	cout << "好基友正在访问" << building->m_sittingroom << endl;
	//cout << "好基友正在访问" << Building->m_bedroom << endl;
}

void test01()
{
	goodgay  gg;
	gg.visit();

}

int main() {

	test01();

	system("pause");
	return 0;
}