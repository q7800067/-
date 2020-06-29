#include <iostream>
using namespace std;

class person {
public:
	person(int age) {
		this->age = age;
	}
	person &personaddage(person& p) {
		this->age += age;
		return *this;
	}
	int age;
};
void test01() {
	person p1(10);
	person p2(10);
	p2.personaddage(p1).personaddage(p1).personaddage(p1);
	cout << "p2µÄÄêÁäÎª" << p2.age << endl;
}
int main() {
	test01( );

}