#include"Pawn.h"

Pawn::Pawn(ChessPoint _pos, bool _is_white) :Piece('p', _pos, _is_white) {}

std::vector<ChessPoint> Pawn::allLegalMoves(const ChessBoard& board) const
{
    std::vector<ChessPoint> moves;
    ChessPoint current_pos = getPosition();
    int direction = isWhite() ? 1 : -1;

    // Check the square in front of the pawn
    ChessPoint front_pos(current_pos.x + direction, current_pos.y);
    if (board.isValidMove(front_pos, isWhite())) 
    {
        moves.push_back(front_pos);

        // If the pawn is in its starting position, it can move two squares ahead
        ChessPoint two_squares_front(current_pos.x + 2 * direction, current_pos.y);
        if (board.isValidMove(two_squares_front, isWhite()) &&
            ((isWhite() && current_pos.x == 1) || (!isWhite() && current_pos.x == 6))) 
        {
            moves.push_back(two_squares_front);
        }
    }

    // Check if the pawn can capture diagonally to the left
    ChessPoint left_diagonal(current_pos.x + direction, current_pos.y - 1);
    if (board.isValidMove(left_diagonal, isWhite()) && board.getPiece(left_diagonal) &&
        board.getPiece(left_diagonal)->isWhite() != isWhite()) 
    {
        moves.push_back(left_diagonal);
    }

    // Check if the pawn can capture diagonally to the right
    ChessPoint right_diagonal(current_pos.x + direction, current_pos.y + 1);
    if (board.isValidMove(right_diagonal, isWhite()) && board.getPiece(right_diagonal) &&
        board.getPiece(right_diagonal)->isWhite() != isWhite())
    {
        moves.push_back(right_diagonal);
    }

    return moves;
}
