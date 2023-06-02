#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] - col == i - row || board[i] - col == row - i)
            return false;
    }
    return true;
}

void placeQueens(vector<int>& board, int row, int n, int& count) {
    if (row == n) {
        count++;
        cout << "Case " << count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            placeQueens(board, row + 1, n, count);
        }
    }
}

void solveNQueens(int n) {
    vector<int> board(n, -1);
    int count = 0;
    placeQueens(board, 0, n, count);
    cout << "Total solutions: " << count << endl;
}

int main() {
    solveNQueens(4);
    return 0;
}