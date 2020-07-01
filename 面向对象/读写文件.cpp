#include <iostream>
#include<string>
#include<fstream>
using namespace std;

void test01() {
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "姓名：张三" << endl;
	ofs << "age：18" << endl;
	ofs.close();
}
void test02() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	////第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}
	////第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}
	//////第三种
	//string buf;
	//while (getline(ifs, buf)) {
	//	cout << buf << endl;
	//}
	//char c;
	//while ((c = ifs.get() != EOF)) {
	//	cout << c;
	//}
}
class person {
public:
	char m_name[64];
	int m_age;
};
void test03() {
	//二进制文件 写文件
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	person p = { "zhangsan ",18 };
	ofs.write((const char*)&p, sizeof(person));
	ofs.close();
	}
void test04() {
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	person p;
	ifs.read((char*)&p, sizeof(person));
	cout << "name" << p.m_name << "age" << p.m_age << endl;
	ifs.close();
}
int main() {
	test04();
}