#include "bsq.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	return c;
}

int	fill_dp(t_map *map)
{
	int	i;
	int	j;
	int	val;

	map->dp = (int **)calloc(map->rows, sizeof(int *));
	if (!map->dp)
		return 0;
	i = 0;
	while (i < map->rows)
	{
		map->dp[i] = (int *)calloc(map->cols, sizeof(int));
		if (!map->dp[i])
			return 0;
		i++;
	}

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				map->dp[i][j] = 0;
			else if (i == 0 || j == 0)
				map->dp[i][j] = 1;
			else
			{
				val = ft_min(map->dp[i - 1][j], map->dp[i][j - 1], map->dp[i - 1][j - 1]) + 1;
				map->dp[i][j] = val;
			}
			j++;
		}
		i++;
	}
	return 1;
}

void	fill_square(t_map *map)
{
	int	i;
	int	j;
	int	best;
	int	best_r;
	int	best_l;

	i = 0;
	best = 0;
	best_l = 0;
	best_r = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->dp[i][j] > best)
			{
				best = map->dp[i][j];
				best_r = i;
				best_l = j;
			}
			j++;
		}
		i++;
	}
	if (best == 0)
		return ;
	i = best_r - best + 1;
	while (i <= best_r)
	{
		j = best_l - best + 1;
		while (j <= best_l)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
}
