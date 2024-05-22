#include "Knight.h"

Knight::Knight(ChessPoint _pos, bool _is_white) :Piece('n', _pos, _is_white) {}

std::vector<ChessPoint> Knight::allLegalMoves(const ChessBoard& board) const
{
    std::vector<ChessPoint> moves;
    ChessPoint current_pos = getPosition();
    std::vector<ChessPoint> available_moves = { 
        ChessPoint(-2, -1), ChessPoint(-2, 1), ChessPoint(2, 1), ChessPoint(2, -1),
        ChessPoint(-1, -2), ChessPoint(-1, 2), ChessPoint(1, 2), ChessPoint(1, -2) };

    for (ChessPoint &a_move : available_moves)
    {
        ChessPoint new_pos = current_pos + a_move;
        if (board.isValidMove(new_pos, isWhite()))
            moves.push_back(new_pos);
    }
    return moves;
}
