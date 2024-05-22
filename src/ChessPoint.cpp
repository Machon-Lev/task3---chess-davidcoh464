#include"ChessPoint.h"

bool operator==(const ChessPoint& p1, const ChessPoint& p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const ChessPoint& p1, const ChessPoint& p2)
{
    return !(p1 == p2);
}

ChessPoint operator+(const ChessPoint& p1, const ChessPoint& p2)
{
	return ChessPoint(p1.x + p2.x, p1.y + p2.y);
}
