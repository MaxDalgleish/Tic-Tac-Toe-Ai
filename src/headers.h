
#include <stdbool.h>
#define ROWS 3
#define COLS 3

typedef struct{
	int row;
	int col;
	int score;
} Move;

Move minimax(char board[3][3], int turn, int depth, Move curr);

int eval_func(char board[3][3]);

bool check_winner(char board[ROWS][COLS]);