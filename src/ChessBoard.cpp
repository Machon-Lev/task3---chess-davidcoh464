#include "ChessBoard.h"

ChessBoard::ChessBoard(std::vector<Piece*> pieces) : _white_turn(true)
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			_board[i][j] = nullptr;

	for (auto piece : pieces)
		setPiece(piece, piece->getPosition());
}

bool ChessBoard::isWhiteTurn() const
{
	return _white_turn;
}

void ChessBoard::changeTurn()
{
	_white_turn = !_white_turn;
}

bool ChessBoard::currectIndex(int i) const 
{
	return (i >= 0 && i < 8);
}

bool ChessBoard::currectIndex(ChessPoint pos) const
{
	return (currectIndex(pos.x) && currectIndex(pos.y));
}


bool ChessBoard::isValidMove(ChessPoint pos, bool is_white) const
{
	if (currectIndex(pos))
	{
		Piece* p = getPiece(pos);
		return p == nullptr || p->isWhite() != is_white;
	}
	return false;
}

Piece* ChessBoard::getPiece(ChessPoint pos) const
{
	if (!currectIndex(pos))
		return nullptr;
	return _board[pos.x][pos.y];
}

void ChessBoard::setPiece(Piece* p, ChessPoint new_pos)
{
	Piece* old_pic = getPiece(new_pos);
	if (old_pic != p)
		delete old_pic;

	_board[new_pos.x][new_pos.y] = p;
	if (p)
	{
		ChessPoint old_pos = p->getPosition();
		if (old_pos != new_pos)
		{
			_board[old_pos.x][old_pos.y] = nullptr;
			p->setPosition(new_pos);
		}
	}
}

void ChessBoard::movePiece(ChessPoint current_pos, ChessPoint new_pos) 
{
	if (!currectIndex(current_pos) || !currectIndex(new_pos))
		throw std::invalid_argument("Invalid position.");

	if (current_pos == new_pos)
		throw std::invalid_argument("Current position equal to the new position.");

	Piece* piece = getPiece(current_pos);	
	if (!piece)
		throw std::invalid_argument("No piece at current position.");

	setPiece(piece, new_pos);
}

bool ChessBoard::checkForCheck(bool is_white_check) const
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			if (_board[i][j] != nullptr && _board[i][j]->isWhite() == is_white_check)
			{
				std::vector<ChessPoint> moves = _board[i][j]->allLegalMoves(*this);
				for (const auto& move : moves)
					if (_board[move.x][move.y] != nullptr && _board[move.x][move.y]->getName() == 'k')
						return true;
			}
		
	return false;
}

bool ChessBoard::isCheckMove(ChessPoint src_pos, ChessPoint dest_pos)
{
	Piece* src_piece = getPiece(src_pos);
	Piece* dest_piece = getPiece(dest_pos);

	// Make a fake move
	_board[src_pos.x][src_pos.y] = nullptr;
	_board[dest_pos.x][dest_pos.y] = src_piece;
	src_piece->setPosition(dest_pos);

	// Check if this move causes the mover to be in check
	bool is_check_move = checkForCheck(src_piece->isBlack());

	// Restore the situation to its original state
	src_piece->setPosition(src_pos);
	_board[src_pos.x][src_pos.y] = src_piece;
	_board[dest_pos.x][dest_pos.y] = dest_piece;

	return is_check_move;
}


ChessBoard::~ChessBoard()
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			if (_board[i][j])
			{
				delete _board[i][j];
				_board[i][j] = nullptr;
			}
}
