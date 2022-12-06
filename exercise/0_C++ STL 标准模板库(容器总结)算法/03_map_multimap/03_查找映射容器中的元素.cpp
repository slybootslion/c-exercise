#include "../head.h"
#include "map_multimap.h"

namespace MapA3 {
void test01() {
  map<string, int> mp;

  mp["admin"] = 100;
  mp["user"] = 200;
  mp["guest"] = 300;

  // 寻找admin是否存在于键值对中
  map<string, int>::iterator pos = mp.find("admin");
  if (pos != mp.end())
	cout << "key = " << pos->first << " --> value = " << pos->second << endl;

  // lower_bound(keyElem) 返回第一个key=keyElem元素的迭代器
  map<string, int>::iterator ret = mp.lower_bound("admin");
  if (ret != mp.end()) {
	cout << "lower_bound key = " << ret->first << " --> lower_bound value = " << ret->second << endl;
  }

  // upper_bound(keyElem) 返回第一个key>keyElem元素的迭代器
  map<string, int>::iterator res = mp.upper_bound("admin");
  cout << "upper_bound key = " << res->first << " --> upper_bound value = " << res->second << endl;
}
}
