#include "bsq.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		fputs(map->grid[i], stdout);
		fprintf(stdout, "\n");
		i++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (i < map->rows)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	i = 0;
	if (map->dp)
	{
		while (i < map->rows)
		{
			free(map->dp[i]);
			i++;
		}
		free(map->dp);
		map->dp = NULL;
	}
}
