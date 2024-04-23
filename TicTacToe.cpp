// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// C++ PROGRAM TO CREATE A TICTACTOE GAME


#include <iostream>
using namespace std;

// character board [3][3] = 3 by 3 grid/board for 'X' and 'O'
// Rules of inference [i] and [j]

//Function to draw game

void drawBoard(char board[3][3])
{
	cout << "-------------------\n";
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << "|";
		}
	}
	cout << "\n-----------------\n";
}

// Check function for a win

bool checkWin(char board[3][3], char player)
{
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] ==
			player && board[i][2] == player)
			return true;
		else if (board[0][i] == player && board[1][i] ==
			player && board[2][i] == player)
			return true;
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		return true;
	else if (board[0][2] == player) && board[1][1] == player && board[2][0] == player)
	return true;
	else
		return false;
}
// main function 
int main() {
	//Initialize the board and players
	char board[3][3] = { {' ', ' ', ' '},
						{' ', ' ', ' '},
						{' ', ' ', ' '} };
	char player = 'X';
	int row, column;
	int turn;

	cout << "Welcome to Aniah's TicTacToe Game!\n";

	// Loop
	for (turn = 0; turn < 9; turn++) {
		drawBoard(board);

		while (true) {
			cout << "Player " << player << " enter row (0-2) and column (0-2): ";
			cin >> row >> column

				if (board[row][column] != ' ' || row < 0 || row > 2 || column < 0 || column > 2) {
					cout << "Invalid move. Please try again loser. \n";
				}
				else {
					break;
				}
		}
		board[row][column] = player;
		if (checkWin(board, player)) {
			drawBoard(board);
			cout << "Player " << player << " wins! Congrats \n";
			break;
		} 
		// Other player '0'
		player = (player == 'X') ? 'O' : 'X';
		
		// End of the game
		drawBoard(board);

		// Check to see if there's declaration of a winner.
		if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) {
			cout << " It's a draw! :|";
		}
		return 0;
	}
}
}