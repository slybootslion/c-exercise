#include "day02.h"

enum weekday
{
	s, m, t, w, thu, f, s1
};

void day02::day02_3() {
	enum weekday wek = s;
	for (int i = wek; i != f; ++i) {
		cout << i << endl;
		cout << wek + s << endl;
		cout << "------------------" << endl;
	}
}
