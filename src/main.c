#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"

void init_array(char arr[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = ' ';
		}
	}
}

void print_board(char board[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%c ", board[i][j]);
			if (j != COLS - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i != ROWS - 1) {
			printf("--+--+--\n");
		}
	}
}

int main(void) {
	int turn = rand() % 2;
	if (turn == 0) {
		printf("Player Starts\n");
	} else {
		printf("CPU starts\n");
	}

	bool game_over = false;

	char board[ROWS][COLS];
	init_array(board);
	
	while (!game_over) {
		print_board(board);

		if (turn == 0) {
			printf("Enter the row and column: ");
			int row, col;
			scanf("%d %d", &row, &col);
			if (board[row - 1][col - 1] == ' ') {
				board[row - 1][col - 1] = 'X';
			} else {
				printf("Invalid move\n");
				continue;
			}
		} else {
			char boardCopy[ROWS][COLS];
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					boardCopy[i][j] = board[i][j];
				}
			}
			// CPU's turn
			// Move minimax(char board[3][3], int turn, int depth, Move curr
			Move temp = {0,0,0};
			Move best_move = minimax(boardCopy, turn, 5, temp);
			boardCopy[best_move.row][best_move.col] = 'O';

		}

		if (check_winner(board)) {
			print_board(board);
			if (turn == 0) {
				printf("Player wins\n");
			} else {
				printf("CPU wins\n");
			}
			game_over = true;
		} else {
			bool draw = true;
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					if (board[i][j] == ' ') {
						draw = false;
						break;
					}
				}
			}
			if (draw) {
				print_board(board);
				printf("Draw\n");
				game_over = true;
			}
		}
		turn = (turn + 1) % 2;
	}
}