#include "Rook.h"

Rook::Rook(ChessPoint _pos, bool _is_white) :Piece('r', _pos, _is_white) {}

std::vector<ChessPoint> Rook::allLegalMoves(const ChessBoard& board) const
{
    std::vector<ChessPoint> moves;
    ChessPoint current_pos = getPosition();

    // check moves in horizontal direction
    // Horizontal rightwards 
    for (int i = current_pos.x + 1; i < 8; ++i)
    {
        ChessPoint new_pos(i, current_pos.y);
        if (board.isValidMove(new_pos, isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break; // stop checking this direction if there's a piece blocking the way
        }
        else
            break; // stop checking this direction if an invalid move is detected
    }
    // Horizontal leftwards 
    for (int i = current_pos.x - 1; i >= 0; --i)
    {
        ChessPoint new_pos(i, current_pos.y);
        if (board.isValidMove(new_pos, isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break;
        }
        else
            break;
    }

    // check moves in vertical direction
    // Vertically upwards
    for (int j = current_pos.y + 1; j < 8; ++j)
    {
        ChessPoint new_pos(current_pos.x, j);
        if (board.isValidMove(new_pos, isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break;
        }
        else
            break;
    }
    // Vertically downwards
    for (int j = current_pos.y - 1; j >= 0; --j)
    {
        ChessPoint new_pos(current_pos.x, j);
        if (board.isValidMove(new_pos, isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break;
        }
        else
            break;
    }

    return moves;
}