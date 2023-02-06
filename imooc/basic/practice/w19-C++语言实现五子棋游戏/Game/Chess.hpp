#ifndef _CHESS_HEAD_H
#define _CHESS_HEAD_H

#include <iostream>

using namespace std;

class Chess
{
private:
    int x;
    int y;
    string color;

public:
    Chess(const string &color, int x, int y) : color(color), x(x), y(y) {}
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
    string getColor() const
    {
        return color;
    }

    virtual void show(void) const = 0;
    virtual ~Chess() {}
};

#endif
