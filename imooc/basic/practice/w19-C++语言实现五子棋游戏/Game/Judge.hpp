#ifndef _JUDGE_HEAD
#define _JUDGE_HEAD

#include "Player.hpp"
#include "ChessBoard.hpp"

class Judge
{
public:
    bool isWin(Player *player)
    {
        return isHorizontalWin(player->getColor()) || isVerticalWin(player->getColor()) ||
        isUphillWin(player->getColor()) || isDownhillWin(player->getColor()) ? true : false;
    }

private:
    bool isHorizontalWin(const string &color)
    {
        int count = 0;
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        int line = chessBoard->getCurrentLine();
        int column = chessBoard->getCurrentColumn();
        for (int i = 0; i < 5; i++)
        {
            if (chessBoard->isSameColorChess(color, line, column + i))
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;
        for (int i = 0; i < 5; i++)
        {
            if (chessBoard->isSameColorChess(color, line, column - i))
                count++;
            else
                break;
        }
        if (count - 1 >= 5)
            return true;
        return false;
    }

    bool isVerticalWin(const string &color)
    {
        int count = 0;
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        int line = chessBoard->getCurrentLine();
        int column = chessBoard->getCurrentColumn();
        for (int i = 0; i < 5; i++)
        {
            bool ok = chessBoard->isSameColorChess(color, line + i, column);
            if (ok)
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;
        for (int i = 0; i < 5; i++)
        {
            bool ok = chessBoard->isSameColorChess(color, line - i, column);
            if (ok)
                count++;
            else
                break;
        }
        if (count - 1 >= 5)
            return true;
        return false;
    }

    bool isUphillWin(const string &color)
    {
        int count = 0;
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        int line = chessBoard->getCurrentLine();
        int column = chessBoard->getCurrentColumn();
        for (int i = 0; i < 5; i++)
        {
            bool ok = chessBoard->isSameColorChess(color, line - i, column + i);
            if (ok)
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;
        for (int i = 0; i < 5; i++)
        {
            bool ok = chessBoard->isSameColorChess(color, line + i, column - i);
            if (ok)
                count++;
            else
                break;
        }
        if (count - 1 >= 5)
            return true;
        return false;
    }

    bool isDownhillWin(const string &color)
    {
        int count = 0;
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        int line = chessBoard->getCurrentLine();
        int column = chessBoard->getCurrentColumn();
        for (int i = 0; i < 5; i++)
        {
            bool ok = chessBoard->isSameColorChess(color, line + i, column + i);
            if (ok)
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;
        for (int i = 0; i < 5; i++)
        {
            bool ok = chessBoard->isSameColorChess(color, line - i, column - i);
            if (ok)
                count++;
            else
                break;
        }
        if (count - 1 >= 5)
            return true;
        return false;
    }
};

#endif
