#include <stdlib.h>
#include <unistd.h>

int	putchar(int c);

static char	read_char(void)
{
	char	c;
	int		ret;

	ret = read(0, &c, 1);
	if (ret <= 0)
		return (0);
	return (c);
}

static void	process_input(char *board, int width, int height)
{
	int		px;
	int		py;
	int		drawing;
	char	cmd;

	px = 0;
	py = 0;
	drawing = 0;
	while ((cmd = read_char()) != 0)
	{
		if (cmd == 'x')
		{
			drawing = !drawing;
		}
		else if (cmd == 'w')
		{
			if (py > 0)
				py--;
		}
		else if (cmd == 's')
		{
			if (py < height - 1)
				py++;
		}
		else if (cmd == 'a')
		{
			if (px > 0)
				px--;
		}
		else if (cmd == 'd')
		{
			if (px < width - 1)
				px++;
		}
		if (drawing)
			board[py * width + px] = 1;
	}
}

static int	count_neighbors(char *board, int width, int height, int x, int y)
{
	int	count;
	int	dx;
	int	dy;
	int	nx;
	int	ny;

	count = 0;
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			if (dx != 0 || dy != 0)
			{
				nx = x + dx;
				ny = y + dy;
				if (nx >= 0 && nx < width && ny >= 0 && ny < height)
					count += board[ny * width + nx];
			}
			dx++;
		}
		dy++;
	}
	return (count);
}

static void	simulate(char **board, int width, int height)
{
	char	*next;
	int		x;
	int		y;
	int		neighbors;
	int		alive;

	next = calloc(width * height, 1);
	if (!next)
		return ;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			neighbors = count_neighbors(*board, width, height, x, y);
			alive = (*board)[y * width + x];
			if (alive && (neighbors == 2 || neighbors == 3))
				next[y * width + x] = 1;
			else if (!alive && neighbors == 3)
				next[y * width + x] = 1;
			else
				next[y * width + x] = 0;
			x++;
		}
		y++;
	}
	free(*board);
	*board = next;
}

static void	print_board(char *board, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (board[y * width + x])
				putchar('0');
			else
				putchar(' ');
			x++;
		}
		putchar('\n');
		y++;
	}
}

int	main(int argc, char **argv)
{
	int		width;
	int		height;
	int		iterations;
	char	*board;
	int		i;

	if (argc != 4)
		return (1);
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	iterations = atoi(argv[3]);
	if (width <= 0 || height <= 0 || iterations < 0)
		return (1);
	board = calloc(width * height, 1);
	if (!board)
		return (1);
	process_input(board, width, height);
	i = 0;
	while (i < iterations)
	{
		simulate(&board, width, height);
		i++;
	}
	print_board(board, width, height);
	free(board);
	return (0);
}
