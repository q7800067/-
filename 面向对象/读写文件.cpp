#include <iostream>
#include<string>
#include<fstream>
using namespace std;

void test01() {
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "����������" << endl;
	ofs << "age��18" << endl;
	ofs.close();
}
void test02() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	////��һ��
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}
	////�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}
	//////������
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
	//�������ļ� д�ļ�
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
		cout << "�ļ���ʧ��" << endl;
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