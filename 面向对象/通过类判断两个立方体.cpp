#include <iostream>
#include <string >
using namespace std;
class cube{
public:
	void setl(int l) {
		m_l = l;
	}
	void seth(int h) {
		m_h = h;
	}
	void setw(int w) {
		m_w= w;
	}
	int geth() {return m_h;}
	int getw() {return m_w;}
	int getl() {return m_l;}
	int caculates() {return 2 * m_l * m_w + 2 * m_w * m_h + 2 * m_l * m_h;}
	int caculatev() {
		return m_l * m_w * m_h;
	}
	bool issamebyclasee(cube& c) {
		if (m_l == c.getl() && m_h == c.geth() && m_w == c.getw()) {
			return true;
		}
	}
private:
	int m_l;
	int m_h;
	int m_w;
};
bool issame(cube& c1, cube& c2) {
	if (c1.getl() == c2.getl() && c1.geth() == c2.geth() && c1.getw() == c2.getw()) {
		return true;
	}
}


int main() {
	cube c1;
	c1.seth(10);
	c1.setw(10);
	c1.setl(10);
	cout << "s:" << c1.caculates ()<< endl;
	cout << "v:" << c1.caculatev ()<< endl;
	cube c2;
	c2.seth(10);
	c2.setw(10);
	c2.setl(10);
	bool ret = issame(c1, c2);
	if (ret) {
		cout << "c1与c2相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
	bool ret1 = c1.issamebyclasee(c2);
	if (ret1) {
		cout << "成员函数判断：c1与c2相等" << endl;
	}
	else {
		cout << "成员函数判断：不相等" << endl;
	}


	system("pause");
	return 0;
}





