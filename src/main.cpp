// Chess 
#include "Chess.h"
#include "ChessEngine.h"
#include <chrono>
#include <thread>


int main()
{
	string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
	//string board = "##########K###############################R#############r#r#####";
	Chess a(board);
	int codeResponse = 0;
	string res = a.getInput();
	while (res != "exit")
	{
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source  
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination 
		21 - illegal movement of that piece 
		31 - this movement will cause you checkmate

		legal movements : 
		41 - the last movement was legal and cause check
		42 - the last movement was legal, next turn 
		*/

		/**/ 
		{ // put your code here instead that code
			cout << "code response >> ";
			try 
			{
				codeResponse = (int)ChessEngine::getInstance(board).movePiece(res);
			}
			catch (const std::invalid_argument& e)
			{
				cout << e.what() << endl;
				std::this_thread::sleep_for(std::chrono::seconds(5));
				codeResponse = 21;
			}
		}
		/**/

		a.setCodeResponse(codeResponse);
		res = a.getInput(); 
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}