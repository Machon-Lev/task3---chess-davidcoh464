#include"Piece.h"

const bool Piece::isWhite() const
{
	return _is_white;
}

const bool Piece::isBlack() const
{
	return !_is_white;
}

const char Piece::getName() const
{
	return _name;
}

ChessPoint Piece::getPosition() const
{
	return _pos;
}

void Piece::setPosition(ChessPoint newPos)
{
	_pos = newPos;
}
