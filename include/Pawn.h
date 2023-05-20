#pragma once
#include "Piece.h"

const bool WHITE_GOING_UP = true;

class Pawn : public Piece
{
public:
	Pawn(ChessPoint _pos, bool _is_white);
	std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const override;
};