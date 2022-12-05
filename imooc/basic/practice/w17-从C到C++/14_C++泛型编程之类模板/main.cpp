#include <iostream>
using namespace std;

template<typename T>
class SeqList {
  public:
	explicit SeqList(int size) {
	  if (size <= 0) {
		cout << "Invalid argument: " << size << endl;
		return;
	  }
	  buf = new T[size];
	  this->size = size;
	  this->index = 0;
	}
	void addData(const T &data) {
	  if (index >= size) {
		cout << "the SeqList is full." << endl;
		return;
	  }
	  buf[index] = data;
	  index++;
	}
	void show() const {
	  for (int i = 0; i < index; ++i)
		cout << buf[i] << endl;
	}
	~SeqList() {
	  if (buf != nullptr)
		delete[] buf;
	}
  private:
	T *buf;
	int size;
	int index;
};

int main() {
  SeqList<string> list(3);
  list.addData("hello");
  list.addData("world");
  list.addData("123");
  list.addData("abc");
  list.show();
  return 0;
}
