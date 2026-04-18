#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_map
{
	char	**grid;
	int		**dp;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

void	solve_map(FILE *fp, int add_newline);
int		parse_header(char *line, t_map *map);
int		read_grid(FILE *fp, t_map *map);
int		validate_grid(t_map *map);
int		fill_dp(t_map *map);
void	fill_square(t_map *map);
void	print_map(t_map *map);
void	free_map(t_map *map);
#endif