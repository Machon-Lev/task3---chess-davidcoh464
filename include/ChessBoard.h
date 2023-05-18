#pragma once

#include <iostream>
#include"ChessPoint.h"
#include "Piece.h"
#include<vector>


class Piece;

/**
 * @brief The ChessBoard class represents a chessboard.
 *
 * The chessboard is a grid of 8x8 squares where pieces can be placed and moved.
 * It keeps track of the current state of the game, including the positions of pieces
 * and the turn of the player.
 */
class ChessBoard
{
    Piece* _board[8][8]; /**< The array representing the chessboard. */
    bool _white_turn; /**< Indicates whether it is currently white's turn to move. */

    /**
     * @brief Checks if the given index is within the valid range for the chessboard.
     * @param i The index to check.
     * @return True if the index is valid, false otherwise.
     */
    bool correctIndex(int i) const;
    
    /**
     * @brief Sets a piece at the specified position on the chessboard.
     * @param pic The piece to set.
     * @param new_pos The new position for the piece.
     */
    void setPiece(Piece* pic, const ChessPoint& new_pos);

public:
    
    /**
     * @brief Constructs a ChessBoard object.
     * @param pieces A vector containing the initial set of pieces to be placed on the board.
     */
    ChessBoard(std::vector<Piece*> pieces);

    /**
     * @brief Checks if the given position is within the valid range for the chessboard.
     * @param pos The position to check.
     * @return True if the position is valid, false otherwise.
     */
    bool correctPosition(const ChessPoint& pos) const;

    /**
     * @brief Checks if it is currently white's turn to move.
     * @return True if it is white's turn, false if it is black's turn.
     */
    bool isWhiteTurn() const;

    /**
     * @brief Changes the turn from white to black, or from black to white.
     */
    void changeTurn();

    /**
     * @brief Checks if the given player color can move to the given position.
     * @param pos The position to check.
     * @param is_white The player color.
     * @return True if the move is valid (position is nullptr or different color), false otherwise.
     */
    bool isValidMove(const ChessPoint& pos, bool is_white) const;

    /**
     * @brief Gets the piece at the specified position on the chessboard.
     * @param pos The position on the chessboard.
     * @return A pointer to the Piece object at the specified position, or nullptr if there is no piece.
     */
    Piece* getPiece(const ChessPoint& pos) const;


    /**
     * @brief Moves a piece from the current position to the new position on the chessboard.
     * @param current_pos The current position of the piece.
     * @param new_pos The new position to move the piece to.
     */
    void movePiece(const ChessPoint& current_pos, const ChessPoint& new_pos);

    /**
     * @brief Checks if the specified player is in check.
     * @param is_white_check Specifies whether to check for check on white or black player.
     * @return True if the specified player is in check, false otherwise.
     */
    bool checkForCheck(bool is_white_check) const;

    /**
     * @brief Checks if moving a piece from the current position to the new position would result in a check.
     * @param current_pos The current position of the piece.
     * @param new_pos The new position to move the piece to.
     * @return True if the move would result in a check, false otherwise.
     */
    bool isCheckMove(const ChessPoint& current_pos, const ChessPoint& new_pos);

    /**
     * @brief Destructor for the ChessBoard object.
     */
    ~ChessBoard();
};






