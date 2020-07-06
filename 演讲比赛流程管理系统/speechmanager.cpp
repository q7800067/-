#include "speechmanager.h"

void speechmanager::showmenu() {
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void speechmanager::exitsystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
}

void speechmanager::initspeech() {
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();

	this->m_index = 1;//初始化轮数
	//初始化记录容器
	this->m_record.clear();
}

void speechmanager::createspeaker()
{
	string nameseed = "ABCDEFGHIJK";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "选手";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		this->v1.push_back(i + 10001);  //创建选手编号，并且放入到v1容器中
		this->m_speaker.insert(make_pair(i + 10001, sp));  //选手编号以及对应选手放入到map容器中
	}
}



void speechmanager::speechdraw() //抽签  v1是哪里来的？创建speechmanager的对象的时候就有了的
{
	cout << "第" << this->m_index << "轮比赛开始抽签了" << endl;
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
	cout << "第" << this->m_index << "轮比赛正式开始" <<endl;
	multimap<double, int, greater<double>> groupscore;  //临时容器，保存key分数value选手编号
	int num = 0;
	vector<int>v_src;  //比赛的人员容器

	if (this->m_index == 1) {
		v_src = v1;
	}
	else {
		v_src = v2;
	}
	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++){
			double score = (rand() % 401 + 600) / 10.f;
			/*cout << score << " ";*/
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());//排序
		d.pop_front();  //去除最高分
		d.pop_back();  //去除最低分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		//打印平均分
		cout << "编号：" << *it << "选手" << this->m_speaker[*it].m_name << "获取平均分" << avg << endl;
		//将平均分放到容器中
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;

		//将打分数据放入到临时小组容器中
		groupscore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号
		//每6人取出前三名
		if (num % 6 == 0) {
			cout << " 第" << num / 6 << "小组比赛名次" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++) {
				cout << "编号：" << it->second << "姓名：" << this->m_speaker[it->second].m_name
					<< "成绩：" << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			int count = 0;
			//取走前三名
			for (multimap<double, int, greater<int>> ::iterator it = groupscore.begin(); it != groupscore.end() && count < 3; it++, count++) {
				if (this->m_index == 1) {v2.push_back((*it).second);}
				else {victory.push_back((*it).second);}
			}
			groupscore.clear();//小组容器清空
		}
	}
	cout << "第" << this->m_index << "轮比赛完毕" << endl;
	cout << endl;
}

void speechmanager::showscore() {  //显示得分
	cout << "-----------第" << this->m_index << "轮晋级选手信息如下----------------------" << endl;
	vector<int>v;
	if (this->m_index == 1) {
		v = v2;
	}
	else {
		v = victory;
		}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "选手编号" << *it << "姓名" << this->m_speaker[*it].m_name << "得分" <<
			this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showmenu();
}
void speechmanager::saverecord() {  //保存信息
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);  //用追加的方式写文件
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++) {
		ofs << *it << "," <<m_speaker[*it].m_score[1] << ",";  //*it为人员编号key，m_speaker[*it]为value
	}	
	ofs << endl;
	ofs.close(); 
	cout << "记录已存储" << endl;
	//有记录了，文件不为空
	this->fileisempty = false;
}
void speechmanager::startspeech() {
	this->speechdraw();
	this->speechcontest();
	this->showscore();
	//第二轮比赛
	this->m_index++;
	this->speechdraw();
	this->speechcontest();
	this->showscore();
	this->saverecord();
	//比赛完毕后，所有数据重置
	this->initspeech();
	this->createspeaker();
	this->loadrecord();
	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}
void speechmanager::loadrecord() {
	ifstream ifs("speech.csv", ios::in);  //读文件
	if (!ifs.is_open()) {
		this->fileisempty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->fileisempty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileisempty = false;
	ifs.putback(ch);  //将上面读取的单个字符放回来
	string data;
	int index = 0;
	while (ifs >> data) {
		/*cout << data << endl;*/
		vector<string>v;
		int pos = -1;  //查到,位置的变量
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}
void speechmanager::showrecord()  //查看往届记录
{
	if (this->fileisempty) {
		cout << "文件不存在，或记录为空" << endl;
	}
	else{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_record[i][0] << " 得分：" << this->m_record[i][1] << " "
				"亚军编号：" << this->m_record[i][2] << " 得分：" << this->m_record[i][3] << " "
				"季军编号：" << this->m_record[i][4] << " 得分：" << this->m_record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
void speechmanager::clearrecord() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化属性
		this->initspeech();
		//创建选手
		this->createspeaker();
		//获取往届记录
		this->loadrecord();
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
speechmanager::speechmanager() {  //构造函数
	this->initspeech();
	this->createspeaker();
	this->loadrecord();
}
speechmanager::~speechmanager() {

}