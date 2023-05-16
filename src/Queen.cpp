#include"Queen.h"

Queen::Queen(ChessPoint _pos, bool _is_white) :Piece('q', _pos, _is_white){}


std::vector<ChessPoint> Queen::allLegalMoves(const ChessBoard& board) const
{
    std::vector<ChessPoint> moves;

    // Compute moves from the Rook
    Rook rook(getPosition(), isWhite());
    std::vector<ChessPoint> rook_moves = rook.allLegalMoves(board);
    moves.insert(moves.end(), rook_moves.begin(), rook_moves.end());

    // Compute moves from the Bishop
    Bishop bishop(getPosition(), isWhite());
    std::vector<ChessPoint> bishop_moves = bishop.allLegalMoves(board);
    moves.insert(moves.end(), bishop_moves.begin(), bishop_moves.end());

    return moves;
}