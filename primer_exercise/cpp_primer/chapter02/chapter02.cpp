#include "chapter02.h"

namespace chapter02
{
	void main() {
		int i, & ri = i;
		i = 5;
		ri = 10;
		cout << i << " " << ri << endl;
	}
}
