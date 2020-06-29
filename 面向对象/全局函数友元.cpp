#include <iostream>
#include <string>
using namespace std;


class building {
	friend void goodgay(building* building);
public:
	building() {
		m_sittingroom = "客厅";
		m_bedroom = "卧室";
	}
public:
	string m_sittingroom;
private:
	string m_bedroom;

};


void goodgay(building* building)
{
	cout << "好基友正在访问" << building->m_sittingroom << endl;
	cout << "好基友正在访问" << building->m_bedroom << endl;
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