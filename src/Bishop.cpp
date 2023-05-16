#include"Bishop.h"

Bishop::Bishop(ChessPoint _pos, bool _is_white) :Piece('b', _pos, _is_white) {}

std::vector<ChessPoint> Bishop::allLegalMoves(const ChessBoard& board) const
{
    std::vector<ChessPoint> moves;
    ChessPoint current_pos = getPosition();

    // check moves in diagonal directions
    // Diagonal to the upper-right
    for (int i = current_pos.x + 1, j = current_pos.y + 1; i < 8 && j < 8; ++i, ++j)
    {
        ChessPoint new_pos(i, j);
        if (board.isValidMove(new_pos, isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break;
        }
        else
            break;
    }
    // Diagonal to the upper-left
    for (int i = current_pos.x - 1, j = current_pos.y + 1; i >= 0 && j < 8; --i, ++j)
    {
        ChessPoint new_pos(i, j);
        if (board.isValidMove(new_pos, isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break;
        }
        else
            break;
    }
    // Diagonal to the lower-left
    for (int i = current_pos.x - 1, j = current_pos.y - 1; i >= 0 && j >= 0; --i, --j)
    {
        ChessPoint new_pos(i, j);
        if (board.isValidMove(new_pos, isWhite()))
        {
            moves.push_back(new_pos);
            if (board.getPiece(new_pos))
                break;
        }
        else
            break;
    }
    // Diagonal to the lower-right
    for (int i = current_pos.x + 1, j = current_pos.y - 1; i < 8 && j >= 0; ++i, --j)
    {
        ChessPoint new_pos(i, j);
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
