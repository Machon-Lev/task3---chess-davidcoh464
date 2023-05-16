#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(ChessPoint _pos, bool _is_white);
	std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const override;
};