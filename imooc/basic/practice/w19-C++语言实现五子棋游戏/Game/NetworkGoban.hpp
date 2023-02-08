#ifndef _NETWORK_GO_BAN_HEAD_H
#define _NETWORK_GO_BAN_HEAD_H

#include "NetworkPlayer.hpp"
#include "KeyHandle.hpp"
#include "Judge.hpp"
#include "WinLogo.hpp"

class NetworkGoban
{
public:
    NetworkGoban(const string &whitePlayerName, const string &blackPlayerName)
    {
        inputInfo();

        fprintf(stderr, "\033[2J"); // 清屏
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        chessBoard->show();
        kh = new KeyHandle;

        if (chessColor == "white")
        {
            whitePlayer = new NetworkPlayer(whitePlayerName, "white", peerIP, peerPort, kh, true);
            blackPlayer = new NetworkPlayer(blackPlayerName, "black", selfIP, selfPort, kh);
        }
        else
        {
            blackPlayer = new NetworkPlayer(blackPlayerName, "black", peerIP, peerPort, kh, true);
            whitePlayer = new NetworkPlayer(whitePlayerName, "white", selfIP, selfPort, kh);
        }
    }
    ~NetworkGoban()
    {
        delete blackPlayer;
        delete whitePlayer;
        delete kh;
    }
    void run(void)
    {
        bool win = false;
        NetworkPlayer *players[] = {blackPlayer, whitePlayer};

        while (!win)
        {
            for (NetworkPlayer *player : players)
            {
                player->waitPlaceChess();
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
    void inputInfo()
    {
        cout << "input chess color: ";
        cin >> chessColor;
        cout << "input self ip: ";
        cin >> selfIP;
        cout << "input self port: ";
        cin >> selfPort;
        cout << "input peer ip: ";
        cin >> peerIP;
        cout << "input peer port: ";
        cin >> peerPort;
    }

private:
    NetworkPlayer *whitePlayer;
    NetworkPlayer *blackPlayer;
    KeyHandle *kh;
    Judge j;
    WinLogo win_logo;
    string chessColor;
    string selfIP;
    string selfPort;
    string peerIP;
    string peerPort;
};

#endif
