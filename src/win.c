#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

bool check_winner(char board[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return true;
		}
	}
	for (int i = 0; i < COLS; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
			return true;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return true;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
		return true;
	}
	return false;
}