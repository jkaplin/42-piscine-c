#include <stdio.h>

#define LENGTH 8
#define WIDTH 8

void	initialize(int board[LENGTH][WIDTH])
{
	int		row;
	int		col;

	row = 0;
	while (row < LENGTH)
	{
		col = 0;
		while (col < WIDTH)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	print_board_placements(int board[LENGTH][WIDTH])
{
	int		row;
	int		col;

	row = 0;
	while (row < LENGTH)
	{
		col = 0;
		while (col < WIDTH)
		{
			if (board[row][col] == 1)
				break;
			col++;
		}
		printf("%d", col + 1);
		row++;
	}
	printf("\n");
}


int		is_legal_col(int board[LENGTH][WIDTH], int col)
{
	int		i;

	i = 0;
	while (i < LENGTH)
	{
		if (board[i][col] == 1)
			return (0);
		i++;
	}
	return (1);
}

int		diagonal(int	board[LENGTH][WIDTH], int row, int col, int factor_r, int factor_c)
{
	int		i;

	i = 1;
	while (row + factor_r * i >= 0 && row + factor_r * i < LENGTH && col + factor_c * i >= 0 && col + factor_c * i < WIDTH)
	{
		if (board[row + factor_r * i][col + factor_c * i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int		is_legal_diagonal(int board[LENGTH][WIDTH], int row, int col)
{
	if (diagonal(board, row, col, -1, -1) &&
			diagonal(board, row, col, -1, 1) &&
			diagonal(board, row, col, 1, -1) &&
			diagonal(board, row, col, 1, 1))
			return (1);
	return (0);
}

int		is_legal_place(int board[LENGTH][WIDTH], int row, int col)
{
	if (is_legal_col(board, col) && is_legal_diagonal(board, row, col))
	{
		return (1);
	}
	return (0);
}

void	solve_puzzle(int board[LENGTH][WIDTH], int row, int col)
{
	if (col == WIDTH)
		return ;
	if (row == LENGTH)
	{
		print_board_placements(board);
		return ;
	}
	if (is_legal_place(board, row, col))
	{
		board[row][col] = 1;
		solve_puzzle(board, row + 1, 0);
		board[row][col] = 0;
		solve_puzzle(board, row, col + 1);
	}
	else
	{
		if (col < WIDTH - 1)
			solve_puzzle(board, row, col + 1);
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int		board[LENGTH][WIDTH];

	initialize(board);
	solve_puzzle(board, 0, 0);
}

int		iterative_eight_queens_puzzle(void)
{
	return (10);
}
