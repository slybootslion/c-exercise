#ifndef W19_C___CHESS_H
#define W19_C___CHESS_H

#include <iostream>

using namespace std;

class Chess
{
public:
	Chess(const string& color, int x, int y) : color(color), x(x), y(y) {
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	string getColor() const {
		return color;
	}

	virtual void show() const = 0;

private:
	string color;
	int x;
	int y;
};

class BlackChess : public Chess
{
public:
	BlackChess(int x, int y) : Chess("black", x, y) {
	}

	void show() const override {
		fprintf(stderr, "\033[%d:%dH\033[43;35m[😀]\033[0m", getY(), getX() - 1);
//		fprintf(stderr, "\033[%d:%dH", getY(), getX());
	}
};

class WhiteChess : public Chess
{
public:
	WhiteChess(int x, int y) : Chess("white", x, y) {
	}

	void show() const override {
		fprintf(stderr, "\033[%d:%dH\033[44;35m[😄]\033[0m", getY(), getX() - 1);
//		fprintf(stderr, "\033[%d:%dH", getY(), getX());
	}
};

#endif
