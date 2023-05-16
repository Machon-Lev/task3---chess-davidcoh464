#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(ChessPoint _pos, bool _is_white);
	std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const override;
};