#include "head.h"

namespace N06 {
class Printer {
  public:
	static Printer *get_instance() {
	  return p_printer;
	}
	void print_text(string text) {
	  cout << "print content：" << text << endl;
	  cout << "printed count: " << m_times << endl;
	  cout << "---------" << endl;
	  m_times++;
	}
  private:
	Printer() {
	  m_times = 0;
	}
	Printer(const Printer &) {}
	static Printer *p_printer;
	int m_times;
};
Printer *Printer::p_printer = new Printer;
void test() {
  Printer *printer = Printer::get_instance();
  printer->print_text("Report on separation");
  printer->print_text("Contract of entry");
  printer->print_text("comment code");
}
}

void single_mod_exercise() {
  N06::test();
}
