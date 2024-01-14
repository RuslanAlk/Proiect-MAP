#include <iostream>
#include <vector>

#define N 8
#define ERROR_INT -1

using namespace std;

int place_count = 1;

void printChessboard(const vector<vector<int>>& chessboard) {
    cout << "Aranjarea numarul " << place_count++ << "/92\n";
    cout << "---------------\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (chessboard[i][j] == 0) {
                cout << ". ";
            } else {
                cout << "Q ";
            }
        }
        cout << "\n";
    }
    cout << "---------------\n";
    cout << "\n";
}

bool isSafe(const vector<vector<int>>& chessboard, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (chessboard[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool placeQueens(vector<vector<int>>& chessboard, int row) {
    if (row == N) {
        printChessboard(chessboard);
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(chessboard, row, col)) {
            chessboard[row][col] = 1;

            foundSolution = placeQueens(chessboard, row + 1) || foundSolution;

            chessboard[row][col] = 0;
        }
    }

    return foundSolution;
}

int main() {
    vector<vector<int>> chessboard(N, vector<int>(N, 0));

    char choice;

    do {
        cout << "Meniu:\n";
        cout << "1. Afiseaza toate solutiile\n";
        cout << "2. Iesire\n";
        cout << "Alegeti optiunea: ";
    citire: try {
        cin >> choice;
        if (!isdigit(choice)) {
            throw ERROR_INT;
        }
    }
    catch (int cod)
    {
        goto citire;
    }

    switch (choice) {
    case '1':
        placeQueens(chessboard, 0);
        break;
    case '2':
        return 0;
        break;
    default:
        cout << "Optiune invalida. Reincercati.\n";
    }

    } while (choice != '2');

    return 0;
}
