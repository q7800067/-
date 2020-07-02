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
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//2�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_empnum();
	/*cout << "ְ������Ϊ" << num << endl;*/
	this->m_empnum = num;

	this->m_emparray = new worker * [this->m_empnum];//���ٿռ�
	this->init_emp(); //���ļ��е����ݣ��浽������
	////���Դ���
	//for (int i = 0; i < this->m_empnum; i++) {
	//	cout << "ְ�����" << this->m_emparray[i]->m_id
	//		<< "����" << this->m_emparray[i]->m_name
	//		<< "���ű��" << this->m_emparray[i]->m_deptid << endl;
	//}

	this->m_empnum = 0;
	this->m_emparray = NULL;
}
//��154��
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
			this->m_fileisempty = false;  //����Ա����Ϊ�ձ�־
			cout << "�ɹ������" << addnum << "����Ա��" << endl;
			this->save();
	}
	else
	{
			cout << "������������������" << endl;
	}
		system("pause");
		system("cls");
	}

int workermanager::get_empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id&& ifs >> name && ifs >> did) {
		num++;
	}
	return num;
}

void workermanager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		worker* worker = NULL;
		if (did == 1) {
			worker = new employee(id, name, did);
		}
		else if (did == 2) {
			worker = new manager(id, name, did);
		}
		else {
			worker = new boss(id, name, did);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}

workermanager::~workermanager()  //�������δ���ͻ����
{
	if (this->m_emparray!=NULL)
	{
		delete[] this->m_emparray;
	}
}

void workermanager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_empnum; i++) {
		ofs << this->m_emparray[i]->m_id << "  "
			<< this->m_emparray[i]->m_name << "  "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	ofs.close();
}
//��ʾԱ��
void workermanager::showemp() {
	if (this->m_fileisempty) {
		cout << "�ļ�������" << endl;
	}
	else {
		for (int i = 0; i < m_empnum; i++) {
			this->m_emparray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
int workermanager::isexist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++) {
		if (this->m_emparray[i]->m_id == id) {
			index = i;
			break;
		}
	}
	return index;
}
//ɾ��ְ��
void  workermanager::del_emp() {

}