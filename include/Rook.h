#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(ChessPoint _pos, bool _is_white);
	std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const override;
	static std::vector<ChessPoint> rookMoves(const Piece* const &_this, const ChessBoard& board);
};