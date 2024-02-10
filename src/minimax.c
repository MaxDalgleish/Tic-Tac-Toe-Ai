#include <stdlib.h>
#include <stdio.h>
#include "main.c"

Move minimax(char board[3][3], int turn, int depth) {
	if (depth == 0) {
		Move move = {0,0,0};
		return move;
	}

	int best_score;
	if (turn == 0) {
		best_score = -1000;
	} else {
		best_score = 1000;
	}

	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				if (turn == 0) {
					board[i][j] = 'X';
					int score = minimax(board, 1, depth - 1);
					board[i][j] = ' ';
					if (score > best_score) {
						best_score = score;
					}
				} else {
					board[i][j] = 'O';
					int score = minimax(board, 0, depth - 1);
					board[i][j] = ' ';
					if (score < best_score) {
						best_score = score;
					}
				}
			}
		}
	}
}