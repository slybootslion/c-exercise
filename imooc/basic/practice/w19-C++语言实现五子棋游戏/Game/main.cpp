#include "./Chess.hpp"
#include "./ChessBoard.hpp"

int main() {
	ChessBoard* chessBoard = ChessBoard::getChessBoard();
	chessBoard->show();

	auto *blackChess = new BlackChess(5, 1);
	auto *whiteChess = new WhiteChess(5, 2);
	chessBoard->placeChess(blackChess);
	chessBoard->placeChess(whiteChess);

	return 0;
}
