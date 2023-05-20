#include"Queen.h"

Queen::Queen(ChessPoint _pos, bool _is_white) :Piece('q', _pos, _is_white){}


std::vector<ChessPoint> Queen::allLegalMoves(const ChessBoard& board) const
{
    std::vector<ChessPoint> moves;

    // Compute moves from the Rook
    std::vector<ChessPoint> rook_moves = Rook::rookMoves(this, board);
    moves.insert(moves.end(), rook_moves.begin(), rook_moves.end());

    // Compute moves from the Bishop
    std::vector<ChessPoint> bishop_moves = Bishop::bishopMoves(this, board);
    moves.insert(moves.end(), bishop_moves.begin(), bishop_moves.end());

    return moves;
}