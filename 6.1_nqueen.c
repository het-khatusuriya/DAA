#include <stdio.h>
#include <stdbool.h>
void printBoard(int board[][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}
bool isSafe(int board[][100], int row, int col, int N) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    // upper diagonal left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // lower diagonal left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}
bool solveNQueens(int board[][100], int col, int N) {
    if (col >= N) {
        return true;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1, N)) {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
int main() {
    int N;
    printf("Enter the value of N for N-Queens: ");
    scanf("%d", &N);
    int board[100][100] = {0};
    if (solveNQueens(board, 0, N)) {
        printf("One valid configuration for %d-Queens:\n", N);
        printBoard(board, N);
    } else {
        printf("Solution does not exist for %d-Queens.\n", N);
    }
    return 0;
}
