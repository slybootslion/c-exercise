#include "../head.h"
#include "map_multimap.h"

namespace MapA2 {
// 通过使用begin/rbegin,end/rend等迭代器，实现对map映射容器元素的正反向遍历
void test01() {
  map<string, int> mp;
  // 三种方式实现map容器插入操作
  mp.insert(pair<string, int>("admin", 100));
  mp.insert(make_pair("user", 200));
  mp["guest"] = 300;

  mp.erase("user"); // 删除第二个数据

  // 正向遍历键值对
  for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
	cout << "key = " << it->first << " --> value = " << it->second << endl;
  }
  print_line();

  // 反向遍历键值对
  for (map<string, int>::reverse_iterator rit = mp.rbegin(); rit != mp.rend(); rit++) {
	cout << "key = " << rit->first << " --> value = " << rit->second << endl;
  }
}
}
