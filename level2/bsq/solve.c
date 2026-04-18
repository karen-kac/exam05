#include "bsq.h"

static void	print_map_error(int add_newline)
{
	(void)add_newline;
	fprintf(stderr, "map error");
	fprintf(stderr, "\n");
}

void	solve_map(FILE *fp, int add_newline)
{
	t_map	map;
	char	*line;
	size_t	len;

	map.grid = NULL;
	map.dp = NULL;
	map.rows = 0;
	map.cols = 0;

	line = NULL;
	len = 0;
	if (getline(&line, &len, fp) == -1)
	{
		free(line);
		print_map_error(add_newline);
		return ;
	}

	if (parse_header(line, &map) == 0)
	{
		free(line);
		print_map_error(add_newline);
		return ;
	}
	free(line);

	if (read_grid(fp, &map) == 0)
	{
		free_map(&map);
		print_map_error(add_newline);
		return ;
	}

	if (validate_grid(&map) == 0)
	{
		free_map(&map);
		print_map_error(add_newline);
		return ;
	}

	if (fill_dp(&map) == 0)
	{
		free_map(&map);
		print_map_error(add_newline);
		return ;
	}

	fill_square(&map);
	print_map(&map);
	if (add_newline)
		fprintf(stdout, "\n");
	free_map(&map);
}
