#include "bsq.h"

int	parse_header(char *line, t_map *map)
{
	int		read;
	int		rows;
	char	empty;
	char	obstacle;
	char	full;

	read = sscanf(line, "%d %c %c %c", &rows, &empty, &obstacle, &full);
	if (read != 4)
		return 0;
	if (rows <= 0)
		return 0;
	if (empty == obstacle || empty == full || obstacle == full)
		return 0;
	map->rows = rows;
	map->empty = empty;
	map->obstacle = obstacle;
	map->full = full;
	return 1;
}

int	read_grid(FILE *fp, t_map *map)
{
	char	*line;
	int		read;
	int		i;
	size_t	len;

	map->grid = (char **)calloc(map->rows, sizeof(char *));
	if (!map->grid)
		return 0;
	i = 0;
	while (i < map->rows)
	{
		line = NULL;
		len = 0;
		read = getline(&line, &len, fp);
		if (read == -1)
		{
			free(line);
			return 0;
		}
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';
		map->grid[i] = line;
		i++;
	}
	return 1;
}

int	validate_grid(t_map *map)
{
	int	i;
	int	j;

	if (!map->grid || !map->grid[0])
		return 0;

	i = 0;
	while (map->grid[0][i])
		i++;
	if (i == 0)
		return 0;
	map->cols = i;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (!(map->grid[i][j] == map->empty || map->grid[i][j] == map->obstacle))
				return 0;
			j++;
		}
		if (j != map->cols)
			return 0;
		i++;
	}

	return 1;
}
