#pragma once
#include "ChessBoard.h"
#include "Response.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

class ChessEngine
{
	ChessBoard* _chess_board;  ///< Pointer to the chess board object

	/**
	 * @brief Converts a character to lowercase.
	 *
	 * This function converts the given character to lowercase.
	 *
	 * @param in The character to convert.
	 * @return The lowercase character.
	 */
	char chartolower(const char& in) const;

	/**
	 * @brief Converts a string position to a ChessPoint object.
	 *
	 * This function converts the given string position to a ChessPoint object.
	 *
	 * @param str_pos The string position to convert.
	 * @return The corresponding ChessPoint object.
	 */
	ChessPoint strToPoint(const std::string& str_pos) const;

	/**
	 * @brief Moves a chess piece from the source position to the destination position.
	 *
	 * This function moves a chess piece from the source position to the destination position.
	 * It returns a Response object indicating the result of the move.
	 *
	 * @param src_pos The source position of the move.
	 * @param dest_pos The destination position of the move.
	 * @return A Response object indicating the result of the move.
	 */
	Response movePiece(const ChessPoint& src_pos, const ChessPoint& dest_pos);

	/**
	 * @brief Constructor for initializing a ChessEngine object with a string representation of the chess board.
	 *
	 * This constructor creates a ChessEngine object and initializes the internal ChessBoard object
	 * with the given string representation of the chess board.
	 *
	 * @param str_board The string representation of the chess board.
	 */
	ChessEngine(const std::string& str_board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");

	/**
	 * @brief Destructor for the ChessEngine object.
	 *
	 * The destructor releases the memory occupied by the ChessBoard object.
	 */
	~ChessEngine();


	// Delete the copy constructor and assignment operator
	ChessEngine(const ChessEngine&) = delete;
	ChessEngine& operator=(const ChessEngine&) = delete;
public:

	/**
	 * @brief Moves a chess piece based on the given move string.
	 *
	 * This function parses the given move string and moves the corresponding chess piece on the chess board.
	 * It returns a Response object indicating the result of the move.
	 *
	 * @param move The move string in the format "source destination".
	 * @return A Response object indicating the result of the move.
	 */
	Response movePiece(const std::string& move);

	/**
	 * @brief Gets the instance of the ChessEngine class.
	 *
	 * This function returns the singleton instance of the ChessEngine class.
	 * If the instance does not exist, it creates a new instance with the given string representation of the chess board.
	 *
	 * @param str_board The string representation of the chess board.
	 * @return The singleton instance of the ChessEngine class.
	 */
	static ChessEngine& getInstance(const std::string& str_board);
};
