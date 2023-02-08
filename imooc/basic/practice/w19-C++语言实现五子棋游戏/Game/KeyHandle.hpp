#ifndef _KEY_HEADLE_HEAD_H
#define _KEY_HEADLE_HEAD_H

#include <iostream>
#include <termios.h>
#include <map>
#include <functional>
#include "Cursor.hpp"

using namespace std;

#define PLACE_CHESS_KEY ' '

class KeyHandle
{
public:
    KeyHandle()
    {
        struct termios attr;
        tcgetattr(0, &attr);              // 获取属性
        attr.c_lflag &= ~(ECHO | ICANON); // 关闭回车确认和回显
        tcsetattr(0, TCSANOW, &attr);     // 设置属性

        auto handleUp = std::bind(&Cursor::move, &cursor, Cursor::UP);
        keyMap.insert(pair<char, function<void()>>('w', handleUp));
        keyMap.insert(pair<char, function<void()>>('W', handleUp));

        auto handleDown = std::bind(&Cursor::move, &cursor, Cursor::DOWN);
        keyMap.insert(pair<char, function<void()>>('s', handleDown));
        keyMap.insert(pair<char, function<void()>>('S', handleDown));

        auto handleLeft = std::bind(&Cursor::move, &cursor, Cursor::LEFT);
        keyMap.insert(pair<char, function<void()>>('a', handleLeft));
        keyMap.insert(pair<char, function<void()>>('A', handleLeft));

        auto handleRight = std::bind(&Cursor::move, &cursor, Cursor::RIGHT);
        keyMap.insert(pair<char, function<void()>>('d', handleRight));
        keyMap.insert(pair<char, function<void()>>('D', handleRight));
    }
    ~KeyHandle()
    {
        struct termios attr;
        tcgetattr(0, &attr);
        attr.c_lflag |= (ECHO | ICANON);
        tcsetattr(0, TCSANOW, &attr);
    }
    void waitPlayerChess(Player *player)
    {
        bool ok = false;
        do
        {
            int ch = getchar();
            if (ch == PLACE_CHESS_KEY)
            {
                ok = player->placeChess(cursor.getX(), cursor.getY());
            }
            else
            {
                auto it = keyMap.find(ch);
                if (it == keyMap.end())
                    continue;
                (it->second)();
            }
        } while (!ok);
    }
    int getCursorX() const
    {
        return cursor.getX();
    }
    int getCursorY() const
    {
        return cursor.getY();
    }
    void setCursorPos(int x, int y)
    {
        cursor.setPos(x, y);
    }

private:
    Cursor cursor;
    map<char, function<void()>> keyMap;
};

#endif
