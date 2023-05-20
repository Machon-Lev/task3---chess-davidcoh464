#pragma once
#include "Rook.h"
#include "Bishop.h"

class Queen : public Piece
{
public:
	Queen(ChessPoint _pos, bool _is_white);
	std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const override;
};