#ifndef W19_C___CHESS_H
#define W19_C___CHESS_H

#include <iostream>

using namespace std;

class Chess
{
public:
	Chess(const string& color, int x, int y);

	int getX() const;

	int getY() const;

	string getColor() const ;

	virtual void show() const = 0;

private:
	int x;
	int y;
	string color;
};

class BlackChess: public Chess {
public:
	BlackChess(int x, int y);
	void show() const override;
};

class WhiteChess: public Chess {
public:
	WhiteChess(int x, int y);
	void show() const override;
};

#endif //W19_C___CHESS_H
