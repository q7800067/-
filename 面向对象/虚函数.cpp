#include <iostream>
#include <string>
using namespace std;

class abstractcalculator {
public:
	int m_num1;
	int m_num2;
	virtual int getresult() {
		return 0;
	}
};
class addcalculator :public abstractcalculator {
public:
	 int getresult() {
		 return m_num1 + m_num2;
	}
};
class subcalculator :public abstractcalculator {
public:
	 int getresult() {
		 return m_num1 - m_num2;
	}
};
class mulcalculator :public abstractcalculator {
public:
	 int getresult() {
		 return m_num1 *m_num2;
	}
};
void test() {
	abstractcalculator* abc = new addcalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getresult() << endl;
	delete abc;
	abc = new subcalculator;

}
int main() {
	test();
}