#include<iostream>

using namespace std;

bool quit; //Boolean to quit the program
bool gameOver; //Boolean to set when the game ends
bool validPos; //Boolean to check if the chosen position is valid

int turn; //variable to show which players turn it is 0 = player 1, and 1 = Player 2
int turnCounter; //variable to keep track of the amount of turns taken

char grid[3][3]; // 2D array of to display the 3x3 tic tac toe grid
int row, column; // variables used to represent elements withint the array

int choice; //variable to hold the grid position choice from the player


/*            Function Declarations             */
void Print(const char*);
void NewLine();
void DrawGrid();
void Setup();
void PlayGame();
void SetPos();
bool Winner();
bool Quit();



int main()
{
	quit = false;

	while (quit == false)
	{
		Setup();

		PlayGame();

		quit = Quit();
	}
	

	return 0;
}


//simple function to print text then end the line
void Print(const char* message)
{
	cout << message << endl;
}

void NewLine()
{
	cout << endl;
}

//Function to draw the grid to the console window
void DrawGrid()
{
	cout << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << endl;
	cout << "----------" << endl;
	cout << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << endl;
	cout << "----------" << endl;
	cout << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << endl;
}

//initialisation function of the required starting values for a new game
void Setup()
{
	gameOver = false;
	validPos = false;

	turn = 0;
	turnCounter = 1;

	grid[0][0] = '1';
	grid[0][1] = '2';
	grid[0][2] = '3';
	grid[1][0] = '4';
	grid[1][1] = '5';
	grid[1][2] = '6';
	grid[2][0] = '7';
	grid[2][1] = '8';
	grid[2][2] = '9';
	

}

//main game function
void PlayGame()
{
	Print("Welcome to TicTacToe!");
	NewLine();
	Print("Player 1 is X and goes first!");
	NewLine();
	Print("Press Enter to start!");

	cin.get();
	NewLine();

	DrawGrid();
	NewLine();

	//Starting the game loop
	while (gameOver == false)
	{
		//player 1
		if (turn == 0)
		{
			validPos = false;
			while (validPos == false) //making sure the position selected is valid using the crated SetPos() function
			{
				Print("Player 1 please enter the number you would like to place an X");
				cin >> choice;
				SetPos();
			}

			if (grid[row][column] != 'X' && grid[row][column] != 'O') //Ensuring the position selected has not already previously been selected
			{
				grid[row][column] = 'X';//set the players move
				DrawGrid();
				turn = 1;
			}
			else
			{
				Print("This position is already in use! Try again!");
			}
		}
		else if (turn == 1) //player 2
		{
			validPos = false;
			while (validPos == false)//making sure the position selected is valid using the crated SetPos() function
			{
				Print("Player 2 please enter the number you would like to place an O");
				cin >> choice;
				SetPos();
			}

			if (grid[row][column] != 'X' && grid[row][column] != 'O')//Ensuring the position selected has not already previously been selected
			{
				grid[row][column] = 'O';//set the players move
				DrawGrid();
				turn = 0;
			}
			else
			{
				Print("This position is already in use! Try again!");
			}
		}

		if (Winner() == false)
		{
			if (turnCounter == 9)//if statement to check if there are no more moves availible on the grid, this will result in a draw
			{
				Print("There are no more spaces! This game is a draw!");
				gameOver = true;
			}
			else
			{
				turnCounter++;
			}
		}


	}
}

//function to check the position the play has chosen is valid and set it to the correct ro and column values for the 2d array
void SetPos()
{
	switch (choice) {
	case 1:
		row = 0;
		column = 0;
		validPos = true;
		break;
	case 2:
		row = 0;
		column = 1;
		validPos = true;
		break;
	case 3:
		row = 0;
		column = 2;
		validPos = true;
		break;
	case 4:
		row = 1;
		column = 0;
		validPos = true;
		break;
	case 5:
		row = 1;
		column = 1;
		validPos = true;
		break;
	case 6:
		row = 1;
		column = 2;
		validPos = true;
		break;
	case 7:
		row = 2;
		column = 0;
		validPos = true;
		break;
	case 8:
		row = 2;
		column = 1;
		validPos = true;
		break;
	case 9:
		row = 2;
		column = 2;
		validPos = true;
		break;
	default:
		cout << "Invalid Move" << endl;
		validPos = false;
		break;
	}
}

//Function to check if a player has won
bool Winner()
{
	for (int i = 0; i < 3; i++)
	{
		if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] || grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
		{
			if (grid[i][0] == 'X')
			{
				Print("Player 1 wins!");
				gameOver = true;
				return true;
			}
			else if (grid[i][0] == 'O')
			{
				Print("Player 2 Wins");
				gameOver = true;
				return true;
			}
		}
	}

	if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] || grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
	{
		if (grid[1][1] == 'X')
		{
			Print("Player 1 wins!");
			gameOver = true;
			return true;
		}
		else if (grid[1][1] == 'O')
		{
			Print("Player 2 Wins");
			gameOver = true;
			return true;
		}
	}

	gameOver = false;
	return false;
}

bool Quit()//check if another game is wanted or not
{
	while (1)
	{
		Print("What would you like to do?");
		Print("1. Quit");
		Print("2. Replay");
		cin >> choice;

		switch (choice)
		{
		case 1:
			return true;
			break;

		case 2:
			for (int i = 0; i < 20; i++) //Stupid way of putting a gap between old and new games, but it works
			{
				NewLine();
			}
			return false;
			break;

		default:
			Print("Invalid Choice");
			break;
		}
	}
}