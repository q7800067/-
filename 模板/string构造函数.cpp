#include<iostream>
#include<string>
using namespace std;
//string();		     					   //����һ���յ��ַ��� ����: string str;
//string(const char* s);			   //ʹ���ַ���s��ʼ��
//`string(const string& str);		   //ʹ��һ��string�����ʼ����һ��string����
//string(int n, char c);				   //ʹ��n���ַ�c��ʼ�� 

void test() {
	string s1; //�������ַ����������޲ι��캯��
	cout << "str1 = " << s1 << endl;
	const char* str = "hello world";
	string s2(str);
	cout << "s2=" << s2 << endl;
	string s3(s2); //���ÿ������캯��
	cout << "str3 = " << s3 << endl;
	
}

int main() {
	test();
}