#include "head.h"

namespace N08 {

class Television {
	friend class Remote;
  private:
	int m_state;
	int m_volume;
	int m_channel;
  public:
	enum { On, Off };
	enum { min_vol, max_vol = 100 };
	enum { min_channel = 1, max_channel = 255 };
	Television() {
	  m_state = Off;
	  m_volume = min_vol;
	  m_channel = min_channel;
	}
	// 打开电视机
	void on_or_off() {
	  this->m_state = this->m_state == On ? Off : On;
	}
	void volume_up() {
	  if (this->m_volume >= max_vol)
		return;
	  this->m_volume++;
	}
	void valume_down (){
	  if (this->m_volume <= min_vol)
		return;
	  this->m_volume--;
	}
	void channel_up () {
	  if (this->m_channel >= max_channel)
		return;
	  this->m_channel++;
	}
	void channel_down() {
	  if (this->m_channel <= min_channel)
		return;
	  this->m_channel--;
	}

};

class Remote {};

void test01() {
  cout << "exercise01()" << endl;
}
void test02() {

}
}

void exercise01() {
  N08::test01();
}
