#include"Piece.h"

bool Piece::isWhite() const
{
	return is_white;
}

bool Piece::isBlack() const
{
	return !is_white;
}

char Piece::getName() const
{
	return name;
}

ChessPoint Piece::getPosition() const
{
	return pos;
}

void Piece::setPosition(ChessPoint newPos)
{
	pos = newPos;
}
