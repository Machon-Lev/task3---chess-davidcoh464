#include "ChessEngine.h"


char ChessEngine::chartolower(const char in) const
{
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

ChessPoint ChessEngine::strToPoint(const std::string str_pos) const
{
	int i = chartolower(str_pos[0]) - 'a';
	int j = str_pos[1] - '1';
	ChessPoint pos(i, j);
	return pos;
}


ChessEngine::ChessEngine(std::string str_board) : _chess_board(nullptr)
{
	std::vector<Piece*> all_piece;
	for (int i = 0; i < str_board.size(); ++i)
	{
		char c = str_board[i];
		if (c == '#')
			continue;

		bool is_white = (c >= 'A' && c <= 'Z');
		char piece_char = chartolower(c);
		ChessPoint pos(i / 8, i % 8);

		Piece* piece = nullptr;
		switch (piece_char)
		{
		case 'p':
			piece = new Pawn(pos, is_white);
			break;
		case 'n':
			piece = new Knight(pos, is_white);
			break;
		case 'b':
			piece = new Bishop(pos, is_white);
			break;
		case 'r':
			piece = new Rook(pos, is_white);
			break;
		case 'q':
			piece = new Queen(pos, is_white);;
			break;
		case 'k':
			piece = new King(pos, is_white);
			break;
		}
		if (piece)
			all_piece.push_back(piece);
	}
	_chess_board = new ChessBoard(all_piece);
}


Response ChessEngine::movePiece(ChessPoint src_pos, ChessPoint dest_pos)
{
	Piece* source_piece = _chess_board->getPiece(src_pos);

	//If there is not piece at the source  
	if (source_piece == nullptr)
		return Response::NO_PIECE;

	//If the piece in the source is piece of your opponent
	if (_chess_board->isWhiteTurn() != source_piece->isWhite())
		return Response::OPPONENT_PIECE;

	//If there one of your pieces at the destination 
	if (!_chess_board->isValidMove(dest_pos, source_piece->isWhite()))
		return Response::YOUR_PIECE_AT_DESTINATION;

	std::vector<ChessPoint> all_moves = source_piece->allLegalMoves(*_chess_board);

	// illegal movement of that piece 
	if (std::find(all_moves.begin(), all_moves.end(), dest_pos) == all_moves.end())
		return Response::ILLEGAL_MOVEMENT;

	// this movement will cause you checkmate
	if (_chess_board->isCheckMove(src_pos, dest_pos))
		return Response::CHECKMATE_MOVE;

	_chess_board->movePiece(src_pos, dest_pos);
	_chess_board->changeTurn();

	// the last movement was legal and cause check
	if (_chess_board->checkForCheck(source_piece->isWhite()))
		return Response::LEGAL_MOVEMENT_CHECK;

	//the last movement was legal, next turn
	return Response::LEGAL_MOVEMENT_NEXT_TURN;
}

Response ChessEngine::movePiece(std::string move)
{
	if(move.size() != 4)
		throw std::invalid_argument("The length of the steps is incorrect (should be 4).");
	ChessPoint src_pos = strToPoint(move.substr(0, 2));
	if(!_chess_board->currectIndex(src_pos))
		throw std::invalid_argument("The source position is incorrect.");
	ChessPoint dest_pos = strToPoint(move.substr(2, 2));
	if (!_chess_board->currectIndex(dest_pos))
		throw std::invalid_argument("The source position is incorrect.");

	return movePiece(src_pos, dest_pos);
}

ChessEngine::~ChessEngine()
{
	delete _chess_board;
	_chess_board = nullptr;
}
