/***********************************************************************************************
** Author: Jeremy Einhorn
** Date: May 30, 2017
** Description: This is the header file for the board TicTacToe which uses the class Board.
***********************************************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"

class TicTacToe
{
private:
	Board board;
	char player;

public:
	TicTacToe(char);
	void play();
};
#endif