#include "head.h"
#include "./Game/Chess.h"

int main() {
//    print_mi::show();
	fprintf(stderr, "\033[2J");
	BlackChess bc(10, 5);
	bc.show();
	WhiteChess wc(10, 6);
	wc.show();
	return 0;
}
