#include "../head.h"
#include "map_multimap.h"

namespace MapA5 {
// 定义三个不同的部门，然后通过映射容器对其进行分组，并实现遍历并打印每个分组

enum { RENLI, YANFA, MEISHU }; // 定义三个部门 RENLI=0
class Worker {
  public:
	string m_name;
	int m_money;
};
// 随机生成5个员工成员
void create_worker(vector<Worker> &v) {
  string name_seed = "ABCDE";
  Worker w;
  unsigned seed = time(0);
  srand(seed);
  for (int i = 0; i < 5; ++i) {
	string name;
	name += name_seed[i];
	int money = rand() % 10000 + 10000;
	w.m_name = name;
	w.m_money = money;
	v.push_back(w);
  }
}
// 实现员工分组
void set_group(vector<Worker> &v, multimap<int, Worker> &m) {
  for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
	int departmentId = rand() % 3; // 随机产生一个部门编号
	m.insert(make_pair(departmentId, *it)); // 将员工分到multimap容器中，1=mp
  }
}
// 打印出指定的部门信息，查其他分组只需修改RENLI为其他即可
void show_group(multimap<int, Worker> &m) {
  cout << "Group: RENLI" << endl;
  multimap<int, Worker>::iterator pos = m.find(RENLI);
  int idx = 0; // 计数器，每次递增，知道登录num
  int num = m.count(RENLI); // 人力部门有多少条数据
  for (; pos != m.end(), idx < num; pos++, idx++) {
	cout << "Name: " << pos->second.m_name << endl;
  }

  cout << "Group: YANFA" << endl;
  auto p2 = m.find(YANFA);
  for (; p2 != m.end(); p2++) {
	cout << "Name: " << p2->second.m_name << endl;
  }

  cout << "Group: MEISHU" << endl;
  auto p3 = m.find(MEISHU);
  for (; p3 != m.end(); p3++) {
	cout << "Name: " << p3->second.m_name << endl;
  }
}

void test01() {
  vector<Worker> v;
  create_worker(v);

  // 实现员工分组，分组的multimap容器
  multimap<int, Worker> mp;
  set_group(v, mp);
  show_group(mp);
}
}
