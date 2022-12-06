#include "../head.h"
#include "map_multimap.h"

namespace MapA4 {
struct StudentInfo {
  string name;
  int year;
  string addr;
};

struct StudentRecord {
  int id;
  StudentInfo student;
};

void test01() {
  StudentRecord sz_array[] = {
	  {1, "admin", 22, "beijing"},
	  {2, "user", 33, "shanghai"},
	  {3, "guest", 24, "jinan"},
  };
  // 创建Map映射
  map<int, StudentInfo> mp;
  // 初始化，将学生数组装入映射
  for (int i = 0; i < 3; ++i) {
	mp[sz_array[i].id] = sz_array[i].student;
  }
  // 迭代遍历Map中的数据
  map<int, StudentInfo>::iterator start, end;
  for (start = mp.begin(); start != mp.end(); start++) {
	cout << "id: " << (*start).first << " --> name: " << (*start).second.name << endl;
  }
  print_line();

  // 迭代寻找mp.find(1)元素，并打印出其内部成员
  map<int, StudentInfo>::iterator i = mp.find(1);
  cout << "id: " << (*i).first << endl;
  cout << "name: " << (*i).second.name << endl;
  cout << "year: " << (*i).second.year << endl;
  cout << "address: " << (*i).second.addr << endl;
}
}
