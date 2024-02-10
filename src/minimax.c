#include <stdlib.h>
#include <stdio.h>
#include "headers.h"

Move minimax(char board[3][3], int turn, int depth, Move curr) {
	if (depth == 0) {
		int result = eval_func(board);
		curr.score = result * (turn == 0 ? 1 : -1);
		curr.score *= 9 - depth;
		return curr;
	}

	// Turn == 0 is the player, Turn == 1 is the CPU
	// CPU wants to get the smallest score possible
	// Player wants the highest score possible
	Move best_move = {-1, -1, 0};
	if (turn == 0) {
		best_move.score = -1000;
	} else {
		best_move.score = 1000;
	}

	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				printf("here\n");
				// Players turn to make a move
				if (turn == 0) {
					board[i][j] = 'X';
					Move made = {i, j, 0};
					Move result = minimax(board, 1, depth - 1, made);
					board[i][j] = ' ';
					if (result.score > best_move.score) {
						printf("%d \n", result.score);
						best_move = result;
					}
				// CPUs turn to make a move
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
	return best_move;
}

int eval_func(char board[3][3]) {
	if (check_winner(board)) {
		return 1;
	} else {
		return 0;
	}
}