#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(ChessPoint _pos, bool _is_white);
	std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const override;
};