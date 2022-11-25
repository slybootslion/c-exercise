#include <iostream>
using namespace std;

class BaseMode {
  public:
	virtual void transmit() {
	  cout << "base transmit" << endl;
	}
};

// 有蓝牙、4G、Wifi三种无线传输数据形式
class Bluetooth : public BaseMode {
  public:
	virtual void transmit() {
	  cout << "bluetooth transmit" << endl;
	}
};
class Wifi : public BaseMode {
  public:
	virtual void transmit() {
	  cout << "wifi transmit" << endl;
	}
};
class _4G : public BaseMode {
  public:
	virtual void transmit() {
	  cout << "4g transmit" << endl;
	}
};

void trans(BaseMode &mod) {
  mod.transmit();
}

int main() {
  Bluetooth bt;
  trans(bt);
  cout << "------------" << endl;
  Wifi wifi;
  trans(wifi);
  cout << "------------" << endl;
  _4G _4g;
  trans(_4g);
  return 0;
}
