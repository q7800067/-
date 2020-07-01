#include <iostream>
#include <string>
using namespace std;
class cpu {
public :
	virtual void calculate() = 0;
};
class gpu {
public:
	virtual void display() = 0;
};
class memory {
public:
	virtual void storage() = 0;
};
class computer {
public:
	computer(cpu* cpu, gpu* vc, memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work() {
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~computer() {  //析构函数
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	cpu* m_cpu;
	gpu* m_vc;
	memory* m_mem;
};
class intercpu :public cpu {
public :
	virtual void calculate(){
		cout << "intercpu来活了" << endl;
	}
};
class intergpu :public gpu {
public:
	virtual void display() {
		cout << "intergpu来活了" << endl;
	}
};
class intermemory :public memory {
public:
	virtual void storage() {
		cout << "intermem来活了" << endl;
	}
};
//------------------------------------------
class lenovocpu :public cpu {
public:
	virtual void calculate() {
		cout << "lenovocpu来活了" << endl;
	}
};
class lenovogpu :public gpu {
public:
	virtual void display() {
		cout << "lenovogpu来活了" << endl;
	}
};
class lenovomemory :public memory {
public:
	virtual void storage() {
		cout << "lenovomem来活了" << endl;
	}
};
//-----------------------------------
void test() {
	cpu* m_intercpu = new intercpu;
	gpu* m_intercard = new intergpu;
	memory* m_intermem = new intermemory;

	computer* computerl = new computer(m_intercpu, m_intercard, m_intermem);
	computerl->work();
	delete computerl;
	cout << "-----------------------" << endl;
	cout << "第二台电脑开始工作：" << endl;
	//第二台电脑组装
	computer* computer2 = new computer(new lenovocpu, new lenovogpu, new lenovomemory);;
	computer2->work();
	delete computer2;

	cout << "-----------------------" << endl;
	cout << "第三台电脑开始工作：" << endl;
	//第三台电脑组装
	computer* computer3 = new computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);;
	computer3->work();
	delete computer3;
}


int main() {
	test();
}