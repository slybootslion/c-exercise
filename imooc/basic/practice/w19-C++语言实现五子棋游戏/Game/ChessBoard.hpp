#ifndef W19_C___CHESSBOARD_H
#define W19_C___CHESSBOARD_H

#include <iostream>
#include "Chess.hpp"

using namespace std;

#define MIN_X 1
#define MIN_Y 1
#define MAX_X 57
#define MAX_Y 29
#define MAX_LINE 15
#define MAX_COLUMN 15
#define X_SKIP 4
#define Y_SKIP 2

class ChessBoard
{
public:
	~ChessBoard() {
		fprintf(stderr, "\033[%d:%dH", MAX_Y + 1, MIN_X);
	}

	static ChessBoard* getChessBoard() {
		if (!chessBoard) chessBoard = new ChessBoard;
		return chessBoard;
	}

	void show() {
		FILE* fp = fopen("ChessBoard.txt", "r");
		if (!fp) {
			perror("fail to fopen ChessBoard.txt");
			return;
		}
		fprintf(stderr, "\033[%d:%dH", MIN_Y, MIN_X);
		char buf[1024];
		while (fgets(buf, sizeof(buf), fp)) {
			fprintf(stderr, "%s", buf);
		}
		fclose(fp);

	}

	void placeChess(const Chess* chess) {
		int line = chess->getY() / Y_SKIP;
		int column = chess->getX() / X_SKIP;
		this->chess[line][column] = chess;
		chess->show();
	}

	class GC
	{
	public:
		~GC() {
			if (chessBoard)
				delete chessBoard;
		}
	};

private:
	ChessBoard() {
		for (int i = 0; i < MAX_LINE; ++i) {
			for (int j = 0; j < MAX_COLUMN; ++j) {
				this->chess[i][j] = nullptr;
			}
		}
	}

	static ChessBoard* chessBoard;
	static GC gc;
	const Chess* chess[MAX_LINE][MAX_COLUMN];
};

ChessBoard* ChessBoard::chessBoard = nullptr;
ChessBoard::GC gc;
#endif //W19_C___CHESSBOARD_H
