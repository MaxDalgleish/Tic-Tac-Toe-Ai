#include <stdlib.h>
#include <stdio.h>
#include "main.c"

Move minimax(char board[3][3], int turn, int depth, Move curr) {
	if (depth == 0) {
		curr.score = eval_func(board);
		return curr;
	}

	// Turn == 0 is the player, Turn == 1 is the CPU
	Move best_move = {0, 0, 0};
	if (turn == 0) {
		best_move.score = -1000;
	} else {
		best_move.score = 1000;
	}

	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				if (turn == 0) {
					board[i][j] = 'X';
					Move made = {i, j, 0};
					Move result = minimax(board, 1, depth - 1, made);
					board[i][j] = ' ';
					if (result.score > best_move.score) {
						best_move = result;
					}
				} else {
					board[i][j] = 'O';
					Move made = {i, j, 0};
					Move result = minimax(board, 0, depth - 1, made);
					board[i][j] = ' ';
					if (result.score < best_move.score) {
						best_move = result;
					}
				}
			}
		}
	}
}

int eval_func(char board[3][3]) {
	if (check_winner(board)) {
		return 1;
	} else {
		return 0;
	}
}