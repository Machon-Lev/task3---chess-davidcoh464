#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(ChessPoint _pos, bool _is_white);
	std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const override;
};