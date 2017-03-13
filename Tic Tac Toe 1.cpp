#include <iostream>
using namespace std;

// 1	2	3
// 4	5	6
// 7	8	9

// X is 1
// O is 2
// 0 is empty

class tictactoe{
	int board[3][3];
	
	public:
		tictactoe();
		void displayBoard();		 		
		int putX(int);
		int putO(int);
		void displayIns(); //instructions
		int takeInput();
		int check(); //check if any player has won
};

int main()
{
	tictactoe game;
	game.displayBoard();
	//system("pause");
	int status=0; //0 means draw
	game.displayIns();

	for(int i=0;i<9;i++)
	{
		game.putX( game.takeInput() ); //input le kar places X (1)
		game.displayBoard();
		if (game.check()==1)
		{
			cout << "X WON\n";
			status = 1;
			break;
		}
		else if(game.check()==2)
		{
			cout << "O WON\n";
			status = 1;
			break;
		}
		game.putO( game.takeInput() ); //input le kar places O (2)
		game.displayBoard();
		if (game.check()==1)
		{
			cout << "X WON\n";
			status = 1;
			break;
		}
		else if(game.check()==2)
		{
			cout << "O WON\n";
			status = 1;
			break;
		}
	
	}	
	
	//draw
	if(status == 0)
	{
		cout << "DRAW\n";
	}
	
	system("pause"); //for running directly
		
//	game.putO( game.takeInput() ); //input le kar places O (2)
//	game.displayBoard();	
//	// 2 places filled
//	game.putX( game.takeInput() ); //input le kar places X (1)
//	game.displayBoard();
//	game.putO( game.takeInput() ); //input le kar places O (2)
//	game.displayBoard();
//	//4 places filled
//	game.putX( game.takeInput() ); //input le kar places X (1)
//	game.displayBoard();
//	game.putO( game.takeInput() ); //input le kar places O (2)
//	game.displayBoard();
//	//6 places filled
//	game.putX( game.takeInput() ); //input le kar places X (1)
//	game.displayBoard();
//	game.putO( game.takeInput() ); //input le kar places O (2)
//	game.displayBoard();
//	// 8 places filled
//	game.putX( game.takeInput() ); //input le kar places X (1)
//	game.displayBoard();
//	
//	//now checking:
//	cout << game.check();	
//	
	
//	for (int i=0;i<9;i++)
//	{
//		cin >>  x;
//		game.putX(x);
//		game.displayBoard();
//	}
	
	
}

int tictactoe::check()
{
	//returns 1 if X has won
	//2 for O
	//0  for no winner
	
	if( board[0][0] == 1  && board[0][1] == 1 && board[0][2] == 1)
	{
		return 1;
	}
	else if(board[1][0] == 1  && board[1][1] == 1 && board[1][2] == 1)
	{
		return 1;
	}
	else if(board[2][0] == 1  && board[2][1] == 1 && board[2][2] == 1)
	{
		return 1;
	}
	else if(board[0][0] == 1  && board[1][1] == 1 && board[2][2] == 1)
	{
		return 1;
	}
	else if(board[0][2] == 1  && board[1][1] == 1 && board[2][0] == 1)
	{
		return 1;
	} //check for X winnong is over
	else if( board[0][0] == 2  && board[0][1] == 2 && board[0][2] == 2)
	{
		return 2;
	}
	else if(board[1][0] == 2  && board[1][1] == 2 && board[1][2] == 2)
	{
		return 2;
	}
	else if(board[2][0] == 2  && board[2][1] == 2 && board[2][2] == 2)
	{
		return 2;
	}
	else if(board[0][0] == 2  && board[1][1] == 2 && board[2][2] == 2)
	{
		return 2;
	}
	else if(board[0][2] == 2  && board[1][1] == 2 && board[2][0] == 2)
	{
		return 2;
	}

	return 0;	
}

int tictactoe::takeInput()
{
	cout << "Enter Poisition: ";
	int x;
	cin >> x;
	return x;
}

void tictactoe::displayIns()
{
	int num=1;
	cout << "Alternate turns starting from X (1), then O (2)\n\n";
	cout << "On the board, 1 means X, 2 means O and 0 means empty cell\n\n";
	cout << "Known Bugs:\n\tYou can overwrite already placed X or O\n\n";
	cout << "Position table:\n";
	for(int i=0;i<3;i++)
	{
		
		for(int j=0;j<3;j++)
		{
			cout << num++ << "\t";			
		}
		
		cout << "\n";
	}	
}

int tictactoe::putX(int location) //returns 1 for success
{
	//does not check for overwriting
	
	switch(location)
	{
		case 1:
			board[0][0] = 1;
			break;
			
		case 2:
			board[0][1] = 1;
			break;
			
		case 3:
			board[0][2] = 1;
			break;
			
		case 4:
			board[1][0] = 1;
			break;
			
		case 5:
			board[1][1] = 1;
			break;
			
		case 6:
			board[1][2] = 1;
			break;
			
		case 7:
			board[2][0] = 1;
			break;
			
		case 8:
			board[2][1] = 1;
			break;
			
		case 9:
			board[2][2] = 1;
			break;
		
		default:
			return 0;
	
	}
	
	return 1; //success
}

int tictactoe::putO(int location) //returns 1 for success
{
	//does not check for overwriting
	
	switch(location)
	{
		case 1:
			board[0][0] = 2;
			break;
			
		case 2:
			board[0][1] = 2;
			break;
			
		case 3:
			board[0][2] = 2;
			break;
			
		case 4:
			board[1][0] = 2;
			break;
			
		case 5:
			board[1][1] = 2;
			break;
			
		case 6:
			board[1][2] = 2;
			break;
			
		case 7:
			board[2][0] = 2;
			break;
			
		case 8:
			board[2][1] = 2;
			break;
			
		case 9:
			board[2][2] = 2;
			break;
		
		default:
			return 0;
	
	}
	
	return 1; //success
}
void tictactoe::displayBoard()
{
	
	system("cls");
	cout << "\t\tBOARD\n\n";
	for(int i=0;i<3;i++)
	{
		cout << "\t";
		
		for(int j=0;j<3;j++)
		{
			cout << board[i][j] << "\t";			
		}
		
		cout << "\n\n";
	}

}

tictactoe::tictactoe()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j] = 0; //0 is empty			
		}
	}
	
}


