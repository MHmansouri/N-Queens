#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int sCounter;  // Counter for the total number of solutions found

#ifdef _WIN32
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#else
void setColor(int color) {
    cout << "\033[" << color << "m";  // Set text color using ANSI escape codes
}
#endif

// Function to print the current state of the chessboard
void printBoard(const vector<int> &board, int lastQueenRow, bool isSolution) {
    int n = board.size();

    // Iterate through each row and column of the chessboard
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j) {
                setColor(isSolution ? FOREGROUND_GREEN : FOREGROUND_RED);  // Set Queen color for solutions
                cout << " Q ";
                setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  // Reset text color
            } else {
                cout << " . ";  // Print an empty square if no Queen is present
            }
        }
        if (i == lastQueenRow) {
            cout << "  <- Move";  // Indicate the last move for visualization
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function to check if placing a Queen at a given position is safe
bool isSafe(const vector<int> &board, int row, int col) {
    // Iterate through each row above the current one
    for (int i = 0; i < row; ++i) {
        // Check if there is a Queen in the same column or diagonals
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;  // Unsafe placement: another Queen is in the same column or diagonals
        }
    }
    return true;  // Safe placement: no Queen in the same column or diagonals
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<int> &board, int row) {
    int n = board.size();

    // Check if all Queens are placed (a solution is found)
    if (row == n) {
        sCounter++;  // Increment the solution counter when a solution is found
        setColor(FOREGROUND_GREEN);
        cout << "[Solution found]\n";
        setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        printBoard(board, -1, true);  // Print the solution board
        return true;
    }

    bool foundSolution = false;
    // Iterate through each column in the current row
    for (int col = 0; col < n; ++col) {
        // Check if placing a Queen in the current position is safe
        if (isSafe(board, row, col)) {
            board[row] = col;  // Place a Queen in the current position

            // Pause for visualization
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            printBoard(board, row, false);  // Print the current state of the board

            // Recur for the next row, and check if a solution is found
            foundSolution = solveNQueens(board, row + 1) || foundSolution;

            board[row] = -1;  // Backtrack by removing the Queen from the current position
        }
    }

    return foundSolution;  // Return whether a solution was found for the current state
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;
    cout << endl;

    // Initialize the chessboard with -1 indicating an empty square
    vector<int> board(n, -1);

    // Check if there is no solution for the given N
    if (!solveNQueens(board, 0)) {
        setColor(FOREGROUND_RED);
        cout << "No solution exists!\n";  // Display if no solution is found
    } else {
        setColor(FOREGROUND_GREEN);
        cout << "Total solutions found: " << sCounter << "\n";  // Display the total number of solutions
    }

    setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  // Reset text color

    return 0;
}
