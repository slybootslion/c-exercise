#ifndef _NETWORK_PLAYER_HEAD_H
#define _NETWORK_PLAYER_HEAD_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>
#include "Player.hpp"
#include "KeyHandle.hpp"

class Point
{
public:
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    const int getX() const { return x; }
    const int getY() const { return y; }

private:
    int x;
    int y;
};

class NetworkPlayer : public Player
{
public:
    NetworkPlayer(const string &name,
                  const string &color,
                  const string &ip,
                  const string &port,
                  KeyHandle *keyHandle,
                  bool localUser = false) : Player(name, color), localUser(localUser), keyHandle(keyHandle)
    {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0)
        {
            perror("Fail to send socket");
            return;
        }

        if (!localUser)
        {
            struct sockaddr_in sockaddr;
            sockaddr.sin_family = AF_INET;
            sockaddr.sin_port = htons(atoi(port.c_str()));
            sockaddr.sin_addr.s_addr = inet_addr(ip.c_str());
            int ret = bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
            if (ret < 0)
            {
                perror("Fail to bind");
                return;
            }
        }
        else
        {
            this->peerIp = ip;
            this->peerPort = port;
        }
    }
    ~NetworkPlayer()
    {
        close(sockfd);
    }
    // 接收坐标
    bool recvPointFromPeer(Point &point)
    {
        int ret = recvfrom(sockfd, (void *)&point, sizeof(point), 0, NULL, NULL);
        if (ret <= 0)
        {
            perror("Fail to recvfrom");
            return false;
        }
        return true;
    }
    // 传输坐标
    bool transPointToPeer(const Point &point, const string &ip, const string &port)
    {
        struct sockaddr_in sockaddr;
        sockaddr.sin_family = AF_INET;
        sockaddr.sin_port = htons(atoi(port.c_str()));
        sockaddr.sin_addr.s_addr = inet_addr(ip.c_str());
        int ret = sendto(sockfd, (void *)&point, sizeof(point), 0, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
        if (ret < 0)
        {
            perror("Fail to sendto");
            return false;
        }
        return true;
    }

    bool placeChess(int x, int y)
    {
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        bool ok = chessBoard->isVaildPostion(x, y);
        if (ok)
        {
            Chess *chess = nullptr;
            if (getColor() == "black")
            {
                chess = new BlackChess(x, y);
            }
            else
            {
                chess = new WhiteChess(x, y);
            }
            chessBoard->placeChess(chess);
        }
        return ok;
    }

    void waitPlaceChess()
    {
        if (!localUser)
        {
            Point point;
            bool ok = recvPointFromPeer(point);
            if (ok)
            {
                int x = point.getX(), y = point.getY();
                keyHandle->setCursorPos(x, y);
                placeChess(x, y);
            }
        }
        else
        {
            keyHandle->waitPlayerChess(this);
            transPointToPeer(Point(keyHandle->getCursorX(), keyHandle->getCursorY()), peerIp, peerPort);
        }
    }

private:
    int sockfd;
    string peerIp;
    string peerPort;
    bool localUser;
    KeyHandle *keyHandle;
};

#endif
