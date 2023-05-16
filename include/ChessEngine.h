#pragma once
#include "ChessBoard.h"
#include "Response.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Pawn.h"
#include"Queen.h"
#include"Rook.h"

class ChessEngine 
{
	ChessBoard *_chess_board;
	char chartolower(const char in) const;
	ChessPoint strToPoint(const std::string str_pos) const;
	Response movePiece(ChessPoint src_pos, ChessPoint dest_pos);
public:
	ChessEngine(std::string str_board);
	Response movePiece(std::string move);
	~ChessEngine();
};