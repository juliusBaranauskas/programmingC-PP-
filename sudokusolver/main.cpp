// A Backtracking program in C++ to solve Sudoku problem 
#include <stdio.h>
#include <cmath>

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0 

// N is used for the size of Sudoku grid. Size will be NxN 
#define N 16 

// This function finds an entry in grid that is still unassigned 
bool FindUnassignedLocation(int grid[N][N], int &row, int &col); 

// Checks whether it will be legal to assign num to the given row, col 
bool isSafe(int grid[N][N], int row, int col, int num); 

/* Takes a partially filled-in grid and attempts to assign values to 
all unassigned locations in such a way to meet the requirements 
for Sudoku solution (non-duplication across rows, columns, and boxes) */
void printGrid(int grid[N][N]);

bool SolveSudoku(int grid[N][N]) 
{ 
	int row, col; 

	// If there is no unassigned location, we are done 
	if (!FindUnassignedLocation(grid, row, col)) 
	return true; // success! 

	// consider digits 1 to 9 
	for (int num = 1; num <= N; num++) 
	{ 
		// if looks promising 
		if (isSafe(grid, row, col, num)) 
		{ 
			// make tentative assignment 
			grid[row][col] = num; 
            printGrid(grid);
			// return, if success, yay! 
			if (SolveSudoku(grid)) 
				return true; 

			// failure, unmake & try again 
			grid[row][col] = UNASSIGNED; 
		} 
	} 
	return false; // this triggers backtracking 
} 

/* Searches the grid to find an entry that is still unassigned. If 
found, the reference parameters row, col will be set the location 
that is unassigned, and true is returned. If no unassigned entries 
remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col) 
{ 
	for (row = 0; row < N; row++) 
		for (col = 0; col < N; col++) 
			if (grid[row][col] == UNASSIGNED) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether an assigned entry 
in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num) 
{ 
	for (int col = 0; col < N; col++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether an assigned entry 
in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num) 
{ 
	for (int row = 0; row < N; row++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether an assigned entry 
within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) 
{ 
	for (int row = 0; row < 4; row++) 
		for (int col = 0; col < 4; col++) 
			if (grid[row+boxStartRow][col+boxStartCol] == num) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether it will be legal to assign 
num to the given row,col location. */
bool isSafe(int grid[N][N], int row, int col, int num) 
{ 
	/* Check if 'num' is not already placed in current row, 
	current column and current 3x3 box */
	return !UsedInRow(grid, row, num) && 
		!UsedInCol(grid, col, num) && 
		!UsedInBox(grid, row - row%(4), col - col%(4), num)&& // 4 should be sqrt(N)
			grid[row][col]==UNASSIGNED; 
} 

/* A utility function to print grid */
void printGrid(int grid[N][N])  

{ 
    printf("\n");
	for (int row = 0; row < N; row++) 
	{ 
	for (int col = 0; col < N; col++) 
			printf("%2d", grid[row][col]); 
		printf("\n"); 
	} 
    printf("\n");
} 

/* Driver Program to test above functions */
int main() 
{ 
	// 0 means unassigned cells 
	int grid[N][N] = {{2, 0, 8, 6, 0, 14, 0, 0, 0, 13, 0, 0, 7, 15, 9, 0}, 
					{0, 10, 0, 0, 0, 16, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
					{0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1, 14, 11, 0, 0, 0}, 
					{0, 14, 0, 13, 0, 15, 1, 0, 2, 7, 0, 0, 0, 4, 0, 0},

					{15, 16, 0, 0, 1, 0, 0, 0, 5, 0, 0, 12, 0, 13, 0, 0}, 
					{7, 0, 0, 8, 0, 0, 16, 5, 0, 0, 0, 2, 0, 3, 0, 0}, 
					{4, 5, 14, 0, 3, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
					{0, 0, 0, 0, 0, 7, 0, 0, 4, 0, 0, 6, 16, 2, 15, 0},

					{13, 0, 0, 0, 0, 11, 0, 10, 0, 8, 2, 4, 0, 0, 5, 9},
					{0, 7, 0, 9, 0, 0, 0, 3, 0, 0, 0, 0, 2, 8, 4, 12},
					{0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 6, 9, 0, 0, 0, 11},
					{0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0},

					{0, 0, 0, 12, 10, 0, 7, 0, 0, 3, 16, 5, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 14, 11, 0, 1, 8, 13, 3, 0, 12, 0},
					{0, 0, 0, 0, 15, 0, 0, 12, 0, 0, 0, 0, 14, 10, 16, 0},
					{0, 6, 10, 0, 0, 3, 0, 13, 9, 0, 0, 7, 0, 0, 11, 0}
					}; 
	if (SolveSudoku(grid) == true) 
		printGrid(grid); 
	else
		printf("No solution exists"); 

	return 0; 
} 
