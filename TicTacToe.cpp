/*****************************************************************************************************
** Author: Jeremy Einhorn
** Date: May 30, 2017
** Description: This is the implementation file for the class TicTacToe as well as the main function
which runs a new gaem of TicTacToe.
******************************************************************************************************/

#include "TicTacToe.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

TicTacToe::TicTacToe(char turn)
{
	//program can accept a lowercase X or O as well as uppercase.  Whichever is chosen, they have the first move
	turn = toupper(turn);
	if (turn == 'X')
		player = 'X';

	if (turn == 'O')
		player = 'O';
}

void TicTacToe::play()
{
	board.print();

	//game continously loops until there is either a winner or the board is full which is a draw
	while (board.gameState() == UNFINISHED)
	{
		int row, col;
		cout << "Player " << player << ": Please enter your desired row number followed by a space, then enter "
			"your desired column number then hit enter." << endl;
		cin >> row >> col;

		while (row > 2 && col > 2)
		{
			cout << "Please only enter 0 - 2 for your choices as they are the only possible spots." << endl;
			cin >> row >> col;
		}

		//if the spot is not occupied, the player is stored in that element
		if (board.makeMove(row, col, player))
		{
			board.makeMove(row, col, player);
			board.print();

			//the game switches to the next player
			if (player == 'X')
				player = 'O';
			else
				player = 'X';
		}

		//if the spot is occupied, the player is told to try again and is given another chance to enter their move
		else
		{
			cout << "That spot is already taken.  Please enter a different spot." << endl;
			board.print();
		}
	}

	//checks for X win
	if (board.gameState() == X_WON)
		cout << "Game over, X won!" << endl;

	//checks for O win
	if (board.gameState() == O_WON)
		cout << "Game over, O won!" << endl;

	//checks for full board
	if (board.gameState() == DRAW)
		cout << "Game over, it is a draw." << endl;
}

int main()
{
	char turn;

	cout << "Please enter which player should go first, X or O." << endl;
	cin >> turn;

	while (turn != 'x' && turn != 'X' && turn != 'o' && turn != 'O')
	{
		cout << "Please only enter x, X, o, or O." << endl;
		cin >> turn;
	}

	TicTacToe game(turn);
	game.play();

	cin.get();
	cin.get();

	return 0;
}