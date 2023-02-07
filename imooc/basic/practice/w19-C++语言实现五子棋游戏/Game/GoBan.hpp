#ifndef _GO_BAN_HEAD
#define _GO_BAN_HEAD

#include "WhitePlayer.hpp"
#include "BlackPlayer.hpp"
#include "KeyHandle.hpp"
#include "Judge.hpp"
#include "WinLogo.hpp"

class GoBan
{
public:
    GoBan(const string &whitePlayerName, const string &blackPlayerName)
    {
        players[0] = new BlackPlayer(blackPlayerName);
        players[1] = new WhitePlayer(whitePlayerName);
        fprintf(stderr, "\033[2J"); // 清屏
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        chessBoard->show();

        kh = new KeyHandle;
    }
    ~GoBan()
    {
        delete players[0];
        delete players[1];
        delete kh;
    }
    void run()
    {

        bool win = false;
        while (!win)
        {
            for (Player *player : players)
            {
                kh->waitPlayerChess(player);
                bool ok = j.isWin(player);
                if (ok)
                {
                    win = true;
                    win_logo.showWiner(*player);
                    break;
                }
            }
        }
    }

private:
    Player *players[2];
    KeyHandle *kh;
    Judge j;
    WinLogo win_logo;
};

#endif
