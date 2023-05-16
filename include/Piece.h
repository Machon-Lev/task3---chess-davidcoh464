#pragma once
#include"ChessBoard.h"
#include<vector>

class ChessBoard;

class Piece
{
private:
	char name;
	bool is_white;
	ChessPoint pos;
public:
	Piece(char _name, ChessPoint _pos, bool _is_white) :name(_name), is_white(_is_white), pos(_pos) {}
	bool isWhite() const;
	bool isBlack() const;
	char getName() const;
	ChessPoint getPosition() const;
	virtual void setPosition(ChessPoint newPos);
	virtual std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const= 0;
};
	
	