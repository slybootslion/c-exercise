#ifndef _WIN_LOGO_HEAD_H
#define _WIN_LOGO_HEAD_H

#include <iostream>
#include "Player.hpp"

#define CHESSBOARD_WIDTH 57
#define CHESSBOARD_HEIGHT 29
#define HORIZONTAL_OFFSET 3

class WinLogo
{
public:
    WinLogo(int x = 0, int y = 0, int width = 25, int height = 15)
    {
        this->width = width;
        this->height = height;
        
        if (!x)
            this->x = CHESSBOARD_WIDTH + HORIZONTAL_OFFSET;
        else
            this->x = x;
        if (!y)
            this->y = (CHESSBOARD_HEIGHT - height) / 2;
        else
            this->y = y;
    }
    void drawRectangle(int x, int y, int width, int height, int backgroundColor)
    {
        fprintf(stderr, "\033[%d;%dH", y, x);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                fprintf(stderr, "\033[%dm \033[0m", backgroundColor);
            }
            fprintf(stderr, "\033[%d;%dH", y + i, x);
        }
    }
    void drawText(int x, int y, const char *text, int fontColor, int background)
    {
        fprintf(stderr, "\033[%d;%dH\033[%d;%dm%s\033[0m", y, x, background, fontColor, text);
    }
    void showWiner(const Player &player)
    {
        drawRectangle(x, y, width, height, 42);
        drawRectangle(x + 2, y + 1, width, height, 47);

        string text1 = "The color is: " + player.getColor();
        drawText(x + 3, y + 1 + height / 2 - 2, text1.c_str(), 33, 47);

        string text2 = "The Winner is: " + player.getName();
        drawText(x + 3, y + 2 + height / 2 - 2, text2.c_str(), 34, 47);

        drawText(x + 3, y + 3 + height / 2 - 2, "The developer: ", 35, 47);
        drawText(x + 6, y + 4 + height / 2 - 2, "SlybootsLion", 36, 47);
    }

private:
    int x;
    int y;
    int width;
    int height;
};

#endif
