#include"workermanager.h"

void workermanager::exitsystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workermanager::showmenu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
workermanager::workermanager() {
	this->m_empnum = 0;
	this->m_emparray = NULL;
}

void workermanager::addemp() {
	cout << "���������ְ������" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) 
	{
		int newsize = this->m_empnum + addnum;//�����¿ռ��С
		worker** newspace = new worker * [newsize];//�����¿ռ�
		if (this->m_emparray != NULL)
		{ //��ԭ�ռ������ݷŵ��¿ռ���
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
		}
			for (int i = 0; i < addnum; i++) { //����������
				int id;
				string name;
				int dselect;
				cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
				cin >> id;
				cout << "�������" << i + 1 << "����ְ������" << endl;
				cin >> name;
				cout << "��ѡ���ְ����λ��" << endl;
				cout << "1��ְͨ��" << endl;
				cout << "2����" << endl;
				cout << "3�ϰ�" << endl;
				cin >> dselect;
				worker* a = NULL;
				switch (dselect) {
				case 1:
					a = new employee(id, name, 1);
					break;
				case 2:
					a = new manager(id, name, 2);
					break;
				case 3:
					a = new boss(id, name, 3);
					break;
				default:
					break;
				}
				newspace[this->m_empnum + i] = a;
			}
			delete[] this->m_emparray;  //�ͷ�ԭ�пռ�
			this->m_emparray = newspace;//�����¿ռ��ָ��
			this->m_empnum = newsize;//�����µĸ���
			cout << "�ɹ������" << addnum << "����Ա��" << endl;
	
	}
	else
	{
			cout << "������������������" << endl;
	}
		system("pause");
		system("cls");
	}





workermanager::~workermanager()  //�������δ���ͻ����
{
	if (this->m_emparray!=NULL)
	{
		delete[] this->m_emparray;
	}
}