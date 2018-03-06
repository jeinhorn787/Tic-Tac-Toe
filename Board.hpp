/*****************************************************************************************************
** Author: Jeremy Einhorn
** Date: May 30, 2017
** Description: This is the header file for the class Board that will setup a game board for TicTacToe.
*******************************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

enum Status{X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
	char board[3][3];

public:
	Board();
	bool makeMove(int, int, char);
	bool isThreeAcross(char);
	bool isThreeDown(char);
	bool isThreeDiagonal(char);
	bool isFull();
	Status gameState();
	void print();
};
#endif