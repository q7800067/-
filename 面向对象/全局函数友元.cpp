#include <iostream>
#include <string>
using namespace std;


class building {
	friend void goodgay(building* building);
public:
	building() {
		m_sittingroom = "����";
		m_bedroom = "����";
	}
public:
	string m_sittingroom;
private:
	string m_bedroom;

};


void goodgay(building* building)
{
	cout << "�û������ڷ���" << building->m_sittingroom << endl;
	cout << "�û������ڷ���" << building->m_bedroom << endl;
}


void test01()
{
	building building;
	goodgay(&building);
}

int main() {
	test01();
	system("pause");
	return 0;
}