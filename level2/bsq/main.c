#include "bsq.h"

static void	print_map_error(int add_newline)
{
	(void)add_newline;
	fprintf(stderr, "map error");
	fprintf(stderr, "\n");
}

int	main (int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		solve_map(stdin, 0);
	}
	else
	{
		i = 1;
		while(i < argc)
		{
			FILE *fp = fopen(argv[i], "r");
			if (!fp)
				print_map_error(argc > 2 && i < argc - 1);
			else
			{
				solve_map(fp, (argc > 2 && i < argc - 1));
				fclose(fp);
			}
			i++;
		}
	}
	return 0;
}
