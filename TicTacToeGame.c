#include <stdio.h>

char board[3][3];   // 3x3 Tic Tac Toe board

void initializeBoard() {
	int i,j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    int i,j;
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][j=0], board[i][1], board[i][2]);
        if (i != 2)
            printf("\n-----------\n");
    }
    printf("\n");
}

int checkWinner() {
    // check rows
    int i;
    for (i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;

    // check columns
    int j;
    for (j = 0; j < 3; j++)
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return 1;

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

int isFull() {
	int i,j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    int row, col, turn = 0;
    char player;

    initializeBoard();

    printf("=== TIC TAC TOE ===\n");
    printf("Player 1: X\nPlayer 2: O\n");

    while (1) {
        printBoard();
        player = (turn % 2 == 0) ? 'X' : 'O';
        printf("\nPlayer %d (%c), enter row and column (1-3): ", (turn % 2) + 1, player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row - 1][col - 1] = player;
        if (checkWinner()) {
            printBoard();
            printf("\nPlayer %d (%c) wins!\n", (turn % 2) + 1, player);
            break;
        }

        if (isFull()) {
            printBoard();
            printf("\nIt's a draw!\n");
            break;
        }

        turn++;
    }

    return 0;
}

