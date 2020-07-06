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
	void speechdraw();  //抽签
	void speechcontest();  //比赛功能实现
	void showscore();
	void saverecord();  //保存记录
	void loadrecord();
	bool fileisempty;
	void showrecord();
	void clearrecord();



	map<int, vector<string>> m_record;
	vector<int>v1;  //保存第一轮比赛 选手编号容器
	vector<int>v2;  //第一轮晋级选手编号容器
	vector<int>victory; //胜出前三名选手编号容器
	map<int, speaker>m_speaker;
	int m_index;
	speechmanager();
	~speechmanager();
};