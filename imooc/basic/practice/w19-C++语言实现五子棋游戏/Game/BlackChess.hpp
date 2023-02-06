#ifndef _BLACK_CHESS_HEAD_H
#define _BLACK_CHESS_HEAD_H

#include "Chess.hpp"

class BlackChess : public Chess
{
public:
    BlackChess(int x, int y) : Chess("black", x, y) {}
    void show() const
    {
        fprintf(stderr, "\033[%d;%dH\033[43;35m[`]\033[0m", getY(), getX() - 1);
        fprintf(stderr, "\033[%d;%dH", getY(), getX());
    }
};

#endif
