 #pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include "speaker.h"
#include<functional>
#include<numeric>
#include<map>
#include<fstream>
class speechmanager {
public:
	void showmenu();
	void exitsystem();
	void initspeech();
	void createspeaker();
	void startspeech();
	void speechdraw();  //��ǩ
	void speechcontest();  //��������ʵ��
	void showscore();
	void saverecord();  //�����¼
	void loadrecord();
	bool fileisempty;
	void showrecord();
	void clearrecord();



	map<int, vector<string>> m_record;
	vector<int>v1;  //�����һ�ֱ��� ѡ�ֱ������
	vector<int>v2;  //��һ�ֽ���ѡ�ֱ������
	vector<int>victory; //ʤ��ǰ����ѡ�ֱ������
	map<int, speaker>m_speaker;
	int m_index;
	speechmanager();
	~speechmanager();
};