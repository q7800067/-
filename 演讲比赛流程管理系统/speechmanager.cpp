#include "speechmanager.h"

void speechmanager::showmenu() {
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void speechmanager::exitsystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
}

void speechmanager::initspeech() {
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();

	this->m_index = 1;//��ʼ������
}

void speechmanager::createspeaker()
{
	string nameseed = "ABCDEFGHIJK";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "ѡ��";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		this->v1.push_back(i + 10001);  //����ѡ�ֱ�ţ����ҷ��뵽v1������
		this->m_speaker.insert(make_pair(i + 10001, sp));  //ѡ�ֱ���Լ���Ӧѡ�ַ��뵽map������
	}
}



void speechmanager::speechdraw() //��ǩ  v1���������ģ�����speechmanager�Ķ����ʱ������˵�
{
	cout << "��" << this->m_index << "�ֱ�����ʼ��ǩ��" << endl;
	if (this->m_index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		system("pause");
		cout << endl;	
	}
}

void speechmanager::speechcontest() {
	cout << "��" << this->m_index << "�ֱ�����ʽ��ʼ" <<endl;
	multimap<double, int, greater<double>> groupscore;  //��ʱ����������key����valueѡ�ֱ��
	int num = 0;
	vector<int>v_src;  //��������Ա����

	if (this->m_index == 1) {
		v_src = v1;
	}
	else {
		v_src = v2;
	}
	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++){
			double score = (rand() % 401 + 600) / 10.f;
			/*cout << score << " ";*/
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());//����
		d.pop_front();  //ȥ����߷�
		d.pop_back();  //ȥ����ͷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		//��ӡƽ����
		cout << "��ţ�" << *it << "ѡ��" << this->m_speaker[*it].m_name << "��ȡƽ����" << avg << endl;
		//��ƽ���ַŵ�������
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;

		//��������ݷ��뵽��ʱС��������
		groupscore.insert(make_pair(avg, *it));//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0) {
			cout << " ��" << num / 6 << "С���������" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++) {
				cout << "��ţ�" << it->second << "������" << this->m_speaker[it->second].m_name
					<< "�ɼ���" << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			int count = 0;
			//ȡ��ǰ����
			for (multimap<double, int, greater<int>> ::iterator it = groupscore.begin(); it != groupscore.end() && count < 3; it++, count++) {
				if (this->m_index == 1) {v2.push_back((*it).second);}
				else {victory.push_back((*it).second);}
			}
			groupscore.clear();//С���������
		}
	}
	cout << "��" << this->m_index << "�ֱ������" << endl;
	cout << endl;
}

void speechmanager::showscore() {  //��ʾ�÷�
	cout << "-----------��" << this->m_index << "�ֽ���ѡ����Ϣ����----------------------" << endl;
	vector<int>v;
	if (this->m_index == 1) {
		v = v2;
	}
	else {
		v = victory;
		}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "ѡ�ֱ��" << *it << "����" << this->m_speaker[*it].m_name << "�÷�" <<
			this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showmenu();
}
void speechmanager::saverecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++) {
		ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
}
void speechmanager::startspeech() {
	this->speechdraw();
	this->speechcontest();
	this->showscore();
	//�ڶ��ֱ���
	this->m_index++;
	this->speechdraw();
	this->speechcontest();
	this->showscore();

	this->saverecord();
	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

speechmanager::speechmanager() {  //���캯��
	this->initspeech();
	this->createspeaker();
}
speechmanager::~speechmanager() {

}