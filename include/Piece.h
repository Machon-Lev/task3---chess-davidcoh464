#pragma once
#include "ChessBoard.h"
#include <vector>

class ChessBoard;

/**
 * @brief Base class representing a chess piece.
 *
 * The Piece class serves as a base class for all types of chess pieces.
 * It provides common functionality and defines pure virtual functions
 * for determining legal moves.
 */
class Piece
{
private:
    const char _name;      ///< Name of the piece
    const bool _is_white;  ///< Flag indicating whether the piece is white
    ChessPoint _pos;       ///< Current position of the piece

public:
    /**
     * @brief Constructor for initializing a Piece object.
     *
     * @param name The name of the piece.
     * @param pos The initial position of the piece.
     * @param is_white Flag indicating whether the piece is white.
     */
    Piece(char name, ChessPoint pos, bool is_white)
        : _name(name), _is_white(is_white), _pos(pos) {}

    /**
     * @brief Checks if the piece is white.
     *
     * @return True if the piece is white, false otherwise.
     */
    const bool isWhite() const;

    /**
     * @brief Checks if the piece is black.
     *
     * @return True if the piece is black, false otherwise.
     */
    const bool isBlack() const;

    /**
     * @brief Gets the name of the piece.
     *
     * @return The name of the piece.
     */
    const char getName() const;

    /**
     * @brief Gets the current position of the piece.
     *
     * @return The current position of the piece.
     */
    ChessPoint getPosition() const;

    /**
     * @brief Sets the position of the piece to a new position.
     *
     * @param newPos The new position to set for the piece.
     */
     void setPosition(const ChessPoint& newPos);

    /**
     * @brief Calculates all legal moves for the piece on the given chess board.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     * It calculates and returns a vector of ChessPoint objects representing all
     * legal moves that the piece can make on the given chess board.
     *
     * @param board The chess board on which the piece resides.
     * @return A vector of ChessPoint objects representing legal moves.
     */
    virtual std::vector<ChessPoint> allLegalMoves(const ChessBoard& board) const = 0;

    /**
     * @brief Virtual destructor for the Piece class.
     *
     * The virtual destructor ensures that derived class objects are properly
     * cleaned up when deleting through a base class pointer.
     */
    virtual ~Piece() = default;
};
