#include "Rook.h"

Rook::Rook(ChessPoint _pos, bool _is_white) :Piece('r', _pos, _is_white) {}

std::vector<ChessPoint> Rook::allLegalMoves(const ChessBoard& board) const
{
    return rookMoves(this, board);
}

std::vector<ChessPoint> Rook::rookMoves(const Piece* const& _this, const ChessBoard& board)
{
    std::vector<ChessPoint> moves;
    ChessPoint current_pos = _this->getPosition();

    // Check moves in vertical direction
    // Vertically upwards
    for (int i = current_pos.x + 1; i < 8; ++i)
    {
        ChessPoint new_pos(i, current_pos.y);
        if (board.isValidMove(new_pos, _this->isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break; // stop checking this direction if there's a piece blocking the way
        }
        else
            break; // stop checking this direction if an invalid move is detected
    }
    // Vertically downwards
    for (int i = current_pos.x - 1; i >= 0; --i)
    {
        ChessPoint new_pos(i, current_pos.y);
        if (board.isValidMove(new_pos, _this->isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break;
        }
        else
            break;
    }

    // Check moves in horizontal direction
    // Horizontally rightwards 
    for (int j = current_pos.y + 1; j < 8; ++j)
    {
        ChessPoint new_pos(current_pos.x, j);
        if (board.isValidMove(new_pos, _this->isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break;
        }
        else
            break;
    }
    // Horizontally leftwards 
    for (int j = current_pos.y - 1; j >= 0; --j)
    {
        ChessPoint new_pos(current_pos.x, j);
        if (board.isValidMove(new_pos, _this->isWhite()))
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
