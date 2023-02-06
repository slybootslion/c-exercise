#ifndef _CHEES_BOARD_HEAD_H
#define _CHEES_BOARD_HEAD_H

#include <iostream>
#include "Chess.hpp"

using namespace std;

#define MIN_X 1
#define MAX_X 57
#define MIN_Y 1
#define MAX_Y 29

#define MAX_LINE 15
#define MAX_COLUMN 15

#define X_STEP 4
#define Y_STEP 2

class ChessBoard
{
public:
    ~ChessBoard()
    {
        fprintf(stderr, "\033[%d;%dH", MAX_Y + 1, MIN_X);
        for (int i = 0; i < MAX_LINE; i++)
            for (int j = 0; j < MAX_COLUMN; j++)
                if (this->chess[i][j])
                    delete chess[i][j];
    }
    static ChessBoard *getChessBoard()
    {
        if (!chessBoard)
            chessBoard = new ChessBoard;
        return chessBoard;
    }
    void show() const
    {
        FILE *fp = fopen("ChessBoard.txt", "r");
        if (!fp)
        {
            perror("Fail to fopen ChessBoard.txt");
            return;
        }
        fprintf(stderr, "\033[%d;%dH", MIN_Y, MIN_X);
        char buf[1024];
        while (fgets(buf, sizeof(buf), fp))
        {
            fputs(buf, stderr);
        }
        fclose(fp);
    }
    void placeChess(const Chess *chess)
    {
        int line = chess->getY() / Y_STEP;
        int column = chess->getX() / X_STEP;

        this->chess[line][column] = chess;
        chess->show();

        currentLine = line;
        currentColumn = column;
    }
    bool isVaildPostion(int x, int y)
    {
        if (x < MIN_X || y < MIN_Y)
            return false;
        if (x > MAX_X || y > MAX_Y)
            return false;
        int line = y / Y_STEP;
        int column = x / X_STEP;
        return chess[line][column] ? false : true;
    }
    class GC
    {
    public:
        ~GC()
        {
            if (chessBoard)
            {
                delete chessBoard;
            }
        }
    };
    bool isSameColorChess(const string &color, int line, int column)
    {
        if (line < 0 || column < 0 || line >= MAX_LINE || column >= MAX_COLUMN)
            return false;

        auto c = this->chess[line][column];
        if (!c || c->getColor() != color)
            return false;
        return true;
    }
    int getCurrentLine() const
    {
        return currentLine;
    }
    int getCurrentColumn() const
    {
        return currentColumn;
    }

private:
    ChessBoard()
    {
        for (int i = 0; i < MAX_LINE; i++)
            for (int j = 0; j < MAX_COLUMN; j++)
                this->chess[i][j] = nullptr;
    }
    static ChessBoard *chessBoard;
    static GC *gc;
    const Chess *chess[MAX_LINE][MAX_COLUMN];
    int currentLine;
    int currentColumn;
};

ChessBoard *ChessBoard::chessBoard = nullptr;
ChessBoard::GC gc;
#endif
