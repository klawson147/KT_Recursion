#include <iostream>
#define N 8


long int tries = 0;

void Print2DArray(int* k);
bool SolveKnightTour(int curX, int curY, int step, int board[N][N], int *posX, int *posY);
bool isValid(int x, int y, int myBoard[N][N]);
int main()
{
	int myBoard[N][N];

	int step = 0;

	// Initialize Array
	for (int x = 0; x < N; x++)
		for (int i = 0; i < N; i++)
			myBoard[x][i] = -1;

	// Possible Knight Positions from Current Position
	int posX[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
	int posY[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };


	// Starting Knight Position
	myBoard[3][3] = step++;

	// If tour is solved print Board
	if (SolveKnightTour(3, 3, step, myBoard, posX, posY))
	{
		Print2DArray(&myBoard[0][0]);
		std::cout << std::endl << "Tries: " << tries << std::endl;
	}
	else
	{
		printf("Solution Unsolved\n");
	}

	return 1;
}

void Print2DArray(int* k)
{
	for (int i = 0; i < N; i++)
	{
		for (int x = 0; x < N; x++)
		{
			printf(" %2d ", *k);
			k++;
		}
		printf("\n");
	}
}

bool SolveKnightTour(int curX, int curY, int step, int board[N][N], int *posX, int *posY)
{
	tries++;
	int i, nextX, nextY;

	// If 64, Tour is Solved
	if (step == N*N)
		return true;


	// Loop Through Possible Knight Positions
	for (i = 0; i < 8; i++)
	{
		// Get Next Positions
		nextX = curX + *(posX + i);
		nextY = curY + *(posY + i);

		// Ensure Next Position is Valid
		if (isValid(nextX, nextY, board))
		{
			board[nextX][nextY] = step;

			// Recursive Call
			if (SolveKnightTour(nextX, nextY, step + 1, board, posX, posY) == true)
			{
				return true;
			}
			else
			{
				// Backtracking; Reset to -1
				board[nextX][nextY] = -1;

			}
		}
	}
	return false;
}

// Determine is Position is Valid
bool isValid(int x, int y, int myBoard[N][N])
{
	return (x >= 0 && x < N && y >= 0 && y < N && myBoard[x][y] == -1);
}
