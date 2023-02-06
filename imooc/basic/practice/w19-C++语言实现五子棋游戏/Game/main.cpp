#include "WhitePlayer.hpp"
#include "BlackPlayer.hpp"
#include "KeyHandle.hpp"
#include "Judge.hpp"

int main()
{
    ChessBoard *chessBoard = ChessBoard::getChessBoard();
    chessBoard->show();

    // BlackChess *blackChess = new BlackChess(5, 1);
    // WhiteChess *whiteChess = new WhiteChess(5, 3);
    // chessBoard->placeChess(blackChess);
    // chessBoard->placeChess(whiteChess);

    // if (chessBoard->isVaildPOstion(5, 1))
    // {
    //     chessBoard->placeChess(new WhiteChess(5, 1));
    // }

    BlackPlayer blackPlayer("tiechui");
    WhitePlayer whitePlayer("cuihua");

    // blackPlayer.placeChess(5, 1);
    // whitePlayer.placeChess(5, 3);

    KeyHandle kh;
    Judge j;
    Player *players[] = {&blackPlayer, &whitePlayer};
    bool win = false;
    while (win != true)
    {
        for (Player *player : players)
        {
            kh.waitPlayerChess(player);
            bool ok = j.isWin(player);
            if (ok)
            {
                win = true;
                break;
            }
        }
    }

    return 0;
}
