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
	//���߱�����  goodgay���е�visit��Ա���� ��Building�����ѣ����Է���˽������
	friend void goodgay::visit();

public:
	Building();

public:
	string m_sittingroom; //����
private:
	string m_bedroom;//����
};

Building::Building()
{
	this->m_sittingroom = "����";
	this->m_bedroom = "����";
}

goodgay::goodgay()
{
	building = new Building;
}

void goodgay::visit()
{
	cout << "�û������ڷ���" << building->m_sittingroom << endl;
	cout << "�û������ڷ���" << building->m_bedroom << endl;
}

void goodgay::visit2()
{
	cout << "�û������ڷ���" << building->m_sittingroom << endl;
	//cout << "�û������ڷ���" << Building->m_bedroom << endl;
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