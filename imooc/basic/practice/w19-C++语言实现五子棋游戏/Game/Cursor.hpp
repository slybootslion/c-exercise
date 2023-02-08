#ifndef _CURSOR_HEAD_H
#define _CURSOR_HEAD_H

#include <iostream>
#include <functional>

using namespace std;

#define MIN_X 1
#define MAX_X 57
#define MIN_Y 1
#define MAX_Y 29

#define X_STEP 4
#define Y_STEP 2

class Cursor
{
public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };
    Cursor()
    {
        x = (MAX_X - MIN_X) / 2 + 1;
        y = (MAX_Y - MIN_Y) / 2 + 1;
        show();
    }
    void show() const
    {
        fprintf(stderr, "\033[%d;%dH", y, x);
    }
    void moveUp()
    {
        if (y <= MIN_Y)
            return;
        y -= Y_STEP;
    }
    void moveDown()
    {
        if (y >= MAX_Y)
            return;
        y += Y_STEP;
    }
    void moveLeft()
    {
        if (x <= MIN_X)
            return;
        x -= X_STEP;
    }
    void moveRight()
    {
        if (x >= MAX_X)
            return;
        x += X_STEP;
    }
    void move(Direction dir)
    {
        auto handle = func[dir];
        handle();
        show();
    }
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
    void setPos(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

private:
    int x;
    int y;
    function<void(void)> func[4] = {
        std::bind(&Cursor::moveUp, this),
        std::bind(&Cursor::moveDown, this),
        std::bind(&Cursor::moveLeft, this),
        std::bind(&Cursor::moveRight, this),
    };
};

#endif
