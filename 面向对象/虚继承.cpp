#include<iostream>
#include<string>
using namespace std;
class animal {
public:
	int m_age;
};
class sheep :public animal {

};
class tuo :public animal {

};
class sheeptuo :public sheep,public tuo {

};
void test() {
	sheeptuo st;
	st.sheep::m_age = 18;
	st.tuo::m_age = 20;
}

int man() {
	system("pause");
	return 0;
}