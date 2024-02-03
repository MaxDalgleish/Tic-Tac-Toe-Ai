#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int result = rand() % 2;
	if (result == 0) {
		printf("Player Starts\n");
	} else {
		printf("CPU starts\n");
	}
}