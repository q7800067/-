#include <iostream>
#include <string>
using namespace std;
class person {
	friend ostream& operator<<(ostream& cout, person& p);
public:person(int a, int b) {
	m_a = a;
	m_b = b;
}
private:
	int m_a;
	int m_b;
};
ostream& operator<<(ostream &cout, person &p) {  //Á´Ê½±à³Ì
	cout << "m_a" << p.m_a << "m_b" << p.m_b << endl;
	return cout;
}
void test() {
	person p(10, 10);

	cout << p << endl;;
}
int main() {
	test();
}