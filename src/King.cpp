#include "King.h"

King::King(ChessPoint _pos, bool _is_white) :Piece('k', _pos, _is_white) {}

std::vector<ChessPoint> King::allLegalMoves(const ChessBoard& board) const
{
    std::vector<ChessPoint> moves;
    ChessPoint current_pos = getPosition();

    // Check all positions around the king
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j) 
        {
            if (i == 0 && j == 0)
                continue; // Skip the current position

            ChessPoint new_pos = current_pos + ChessPoint(i, j);
            if (board.isValidMove(new_pos, isWhite())) 
            {
                moves.push_back(new_pos);
            }
        }
    }
    // Optional add check for castling on the king's side
    return moves;
}