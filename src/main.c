#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

typedef struct{
	int row;
	int col;
	int score;
} Move;

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
	print_board(board);
	
	while (!game_over) {
		char boardCopy[ROWS][COLS];
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				boardCopy[i][j] = board[i][j];
			}
		}

		minimax(boardCopy, turn, 5);
	}
}