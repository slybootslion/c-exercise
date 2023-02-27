#include "link.h"

namespace link
{
	// CC7 牛牛的单向链表
	class Link
	{
	public:
		int val = 0;
		Link* next = nullptr;
	};

	void cc7() {
		int n, v;
		cin >> n;
		Link* head = new Link();
		Link* p = head;
		for (int i = 0; i < n; i++) {
			cin >> v;
			p->next = new Link();
			p->next->val = v;
			p = p->next;
		}
		p = head->next;
		for (int i = 0; i < n; i++) {
			cout << p->val << " ";
			p = p->next;
		}
	}

	// CC8 牛牛的链表交换
	void cc8() {
		int n, v;
		cin >> n;
		Link* head = new Link();
		Link* p = head;
		for (int i = 0; i < n; i++) {
			cin >> v;
			p->next = new Link();
			p->next->val = v;
			p = p->next;
		}

		p = head->next;
		head->next = p->next;
		p->next = p->next->next;
		head->next->next = p;

		p = head->next;
		for (int i = 0; i < n - 3; i++)
			p = p->next;
		Link* t = p->next;
		p->next = t->next;
		t->next = nullptr;
		p->next->next = t;

		p = head->next;
		for (int i = 0; i < n; i++) {
			cout << p->val << " ";
			p = p->next;
		}
	}

	void main() {
//		cc7();
		cc8();

	}
}
