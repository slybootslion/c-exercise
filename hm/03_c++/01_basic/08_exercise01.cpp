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
	void volume_down() {
	  if (this->m_volume <= min_vol)
		return;
	  this->m_volume--;
	}
	void channel_up() {
	  if (this->m_channel >= max_channel)
		return;
	  this->m_channel++;
	}
	void channel_down() {
	  if (this->m_channel <= min_channel)
		return;
	  this->m_channel--;
	}
	void show_tel_state() {
	  string state = m_state == On ? "is open" : "is closed";
	  cout << "open state: " << state << endl;
	  if (m_state == On) {
		cout << "volume is: " << m_volume << endl;
		cout << "channel is: " << m_channel << endl;
	  }
	  print_line();
	}
};

class Remote {
  private:
	Television *p_television;
  public:
	Remote(Television *television) {
	  p_television = television;
	}
	void on_or_off() {
	  p_television->on_or_off();
	}
	void volume_up() {
	  p_television->volume_up();
	}
	void volume_down() {
	  p_television->volume_down();
	}
	void channel_up() {
	  p_television->channel_up();
	}
	void channel_down() {
	  p_television->channel_down();
	}
	void set_channel(int channel) {
	  if (channel < Television::min_channel || channel > Television::max_channel)
		return;
	  p_television->m_channel = channel;
	}
	void show_tel_state() {
	  p_television->show_tel_state();
	}
};

void test01() {
  Television television;
  television.show_tel_state();
  television.on_or_off();
  television.volume_up();
  television.volume_up();
  television.volume_up();
  television.volume_up();
  television.channel_up();
  television.channel_up();
  television.show_tel_state();
}
void test02() {
  Television television;
  Remote remote(&television);
  remote.on_or_off();
  remote.channel_up();
  remote.channel_up();
  remote.channel_up();
  remote.volume_up();
  remote.volume_up();
  remote.volume_up();
  remote.volume_up();
  remote.show_tel_state();
}
}

void exercise01() {
//  N08::test01();
  N08::test02();
}
