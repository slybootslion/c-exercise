#include "../head.h"
#include "map_multimap.h"

namespace MapA1 {
void test01() {
  // 创建的对组字符串
  pair<string, int> p("hello", 100);
  pair<string, int> p2 = make_pair("gorillaz", 200);
  cout << "name: " << p.first << endl;
  cout << "age: " << p.second << endl;

  print_line();

  // 检测集合元素是存在重复的，如果出现重复的则报错
  set<int> var;
  var.insert(10);
//  pair<set<int>::iterator, bool> ret = var.insert(20);
  pair<set<int>::iterator, bool> ret = var.insert(10);
  if (!ret.second)
	cout << "insert error" << endl;
  else
	cout << ret.first.operator->() << endl;
}
}
