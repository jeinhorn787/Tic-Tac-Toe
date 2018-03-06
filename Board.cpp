/***********************************************************************************************************************
** Author: Jeremy Einhorn
** Date: May 30, 2017
** Description: This is the implementation file using the Board class.  It includes creating an empty board, 
making a valid move on the board, and testing the game state.
************************************************************************************************************************/

#include "Board.hpp"
#include <iostream>
using std::cout;
using std::endl;

Board::Board()
{
	//sets up board with dots filling all 9 elements of the array
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = '.';	
}

bool Board::makeMove(int row, int col, char player)
{
	bool valid = false;
	
	//if a dot currently exsits in the move entered, it is a valid move and the player is stored in that element
	//otherwise, the spot is already taken and the player is not stored in the element
	if (board[row][col] == '.')
	{
		board[row][col] = player;
		valid = true;
	}

	return valid;
}

bool Board::isThreeAcross(char player)	//will be used in gameState to test for win across
{
	bool status = false;

	//if tictactoe is reached across the first row
	if (board[0][0] == player)
	{
		if (board[0][1] == player)
		{
			if (board[0][2] == player)
				status = true;
		}
	}

	//if tictactoe is reached across the second row
	if (board[1][0] == player)
	{
		if (board[1][1] == player)
		{
			if (board[1][2] == player)
				status = true;
		}
	}

	//if tictactoe is reached across the thrid row
	if (board[2][0] == player)
	{
		if (board[2][1] == player)
		{
			if (board[2][2] == player)
				status = true;
		}
	}

	return status;
}

bool Board::isThreeDown(char player)	//will be used in gameState to test for win down
{
	bool status = false;

	//if tictactoe is reached down the first column
	if (board[0][0] == player)
	{
		if (board[1][0] == player)
		{
			if (board[2][0] == player)
				status = true;
		}
	}

	//if tictactoe is reached down the second column
	if (board[0][1] == player)
	{
		if (board[1][1] == player)
		{
			if (board[2][1] == player)
				status = true;
		}
	}

	//if tictactoe is reached down the third column
	if (board[0][2] == player)
	{
		if (board[1][2] == player)
		{
			if (board[2][2] == player)
				status = true;
		}
	}

	return status;
}

bool Board::isThreeDiagonal(char player)	//will be used in gameState to test if win diagonally
{
	bool status = false;

	//if tictactoe is reached in the first possible diagonal
	if (board[0][0] == player)
	{
		if (board[1][1] == player)
		{
			if (board[2][2] == player)
				status = true;
		}
	}

	//if tictactoe is reached in the second possible diagonal
	if (board[0][2] == player)
	{
		if (board[1][1] == player)
		{
			if (board[2][0] == player)
				status = true;
		}
	}

	return status;
}

bool Board::isFull()	//will be used in gameState to test if the board is totally full of moves
{
	bool status = true;
	
	//if a dot is reached in any of the elements, the board is not full
	for (int i=0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '.')
				status = false;
		}

	return status;
}

Status Board::gameState()
{
	//game is continually UNFINISHED if none of the if statements execute
	Status status = UNFINISHED;

	//checks if X won either across, down, or diagonally
	if (isThreeAcross('X'))
		status = X_WON;

	if (isThreeDown('X'))
		status = X_WON;

	if (isThreeDiagonal('X'))
		status = X_WON;

	//checks if O won either across, down, or diagonally
	if (isThreeAcross('O'))
		status = O_WON;

	if (isThreeDown('O'))
		status = O_WON;

	if (isThreeDiagonal('O'))
		status = O_WON;

	if (isFull())
		status = DRAW;

	return status;
}

void Board::print()
{
	cout << "  0 1 2" << endl;
	cout << "0 " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
	cout << "1 " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
	cout << "2 " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
}