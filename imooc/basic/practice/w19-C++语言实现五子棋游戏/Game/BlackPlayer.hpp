#ifndef _BLACK_PLAYER_HEAD_H
#define _BLACK_PLAYER_HEAD_H

#include "Player.hpp"
#include "ChessBoard.hpp"
#include "BlackChess.hpp"
class BlackPlayer : public Player
{
public:
    BlackPlayer(const string &name):Player(name, "black"){};
    bool placeChess(int x, int y) {
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        bool ok = chessBoard->isVaildPostion(x, y);
        if (ok) {
            chessBoard->placeChess(new BlackChess(x, y));
            return true;
        }
        return false;
    }
};

#endif
