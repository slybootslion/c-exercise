#include "Chess.h"

Chess::Chess(const string& color, int x, int y) : color(color), x(x), y(y) {
}

int Chess::getX() const {
	return x;
}

int Chess::getY() const {
	return y;
}

string Chess::getColor() const {
	return color;
}

BlackChess::BlackChess(int x, int y) : Chess("black", x, y) {
}

void BlackChess::show() const {
	fprintf(stderr, "\033[%d:%dH\033[43;35m[😀]\033[0m", getY(), getX() - 1);
	fprintf(stderr, "\033[%d:%dH", getY(), getX());
}

WhiteChess::WhiteChess(int x, int y) : Chess("white", x, y) {
}

void WhiteChess::show() const {
	fprintf(stderr, "\033[%d:%dH\033[44;35m[😄]\033[0m", getY(), getX() - 1);
	fprintf(stderr, "\033[%d:%dH", getY(), getX());
}
