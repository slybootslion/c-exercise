#include "lst.h"
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <algorithm>

namespace lst
{
	// CPP47 迭代器遍历容器
	void cpp47() {
		vector<int> v;
		int a;
		for (int i = 0; i < 5; i++) {
			cin >> a;
			v.push_back(a);
		}
		auto it = v.begin();
		while (it != v.end()) {
			cout << *it << ' ';
			it++;
		}
		cout << endl;
		it = v.end();
		while (it != v.begin()) {
			it--;
			cout << *it << ' ';
		}
	}

	// CPP68 迭代器遍历set
	void cpp68() {
		set<int> s;
		int a;
		for (int i = 0; i < 5; i++) {
			{
				cin >> a;
				s.insert(a);
			}
		}
		for (int it: s) {
			cout << it << " ";
		}
	}

	// CPP48 智能排队系统
	class Guest
	{
	public:
		string name;
		bool vip;

		Guest(string name, bool vip) {
			this->name = name;
			this->vip = vip;
		}
	};

	void cpp48() {
		Guest guest1("张三", false);
		Guest guest2("李四", false);
		Guest vipGuest("王五", true);
		deque<Guest> deque;

		deque.push_back(guest1);
		deque.push_back(guest2);
		deque.push_front(vipGuest);

		for (const Guest& g: deque) {
			cout << g.name << " ";
		}
	}

	// CPP69 最后k个元素
	void cpp69() {
		int n, k;
		vector<int> a;
		cin >> n >> k;
		int num = 0;
		for (int i = 0; i < n; i++) {
			cin >> num;
			a.push_back(num);
		}
		auto it = a.end();
		while (k > 0) {
			it--;
			cout << *it << " ";
			k--;
		}
	}

	// CPP49 去除字符串中重复的字符
	void cpp49() {
		char str[100] = { 0 };
		cin.getline(str, sizeof(str));

		set<char> s;
		char* p = str;
		while (*p != '\0') {
			s.insert(*p);
			p++;
		}

		for (auto c: s)
			cout << c;
	}

	// CPP50 统计字符串中各字母字符对应的个数
	void cpp50() {
		char str[100] = { 0 };
		cin.getline(str, sizeof(str));
		map<char, int> m;
		for (char c: str) {
			if (isalpha(c))
				m[c]++;
		}
		for (auto i: m)
			cout << i.first << ":" << i.second << endl;
	}

	// CPP70 查找
	void cpp70() {
		set<int> s;
		int n, m, a, x;
		cin >> n >> m;
		while (n--) {
			cin >> a;
			s.insert(a);
		}
		while (m--) {
			cin >> x;
			auto it = s.upper_bound(x);
			if (it == s.end())
				cout << -1 << endl;
			else
				cout << *it << endl;
		}
	}

	// CPP71 判断元素是否出现
	void cpp71() {
		map<int, string> ma;
		int n, m, a;
		cin >> n >> m;

		while (n--) {
			cin >> a;
			ma[a] = "yes";
		}

		while (m--) {
			cin >> a;
			auto it = ma.find(a);
			if (it == ma.end())
				cout << "no" << endl;
			else
				cout << it->second << endl;
		}
	}

	// CPP51 使用算法
	void show(int a) {
		cout << a << " ";
	}

	void cpp51() {
		int num;
		vector<int> v;
		for (int i = 0; i < 5; i++) {
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end(), greater<int>());
		for_each(v.begin(), v.end(), show);
	}

	// CPP72 找到数组里的第k大数(C++)
	void cpp72() {
		int n, k, num;
		vector<int> a;
		cin >> n >> k;
		while (n--) {
			cin >> num;
			a.push_back(num);
		}
		sort(a.begin(), a.end());
		cout << a[k - 1];
	}

	void main() {
//		cpp47();
//		cpp68();
//		cpp48();
//		cpp69();
//		cpp49();
//		cpp50();
//		cpp70();
//		cpp71();
//		cpp51();
		cpp72();

	}
}
