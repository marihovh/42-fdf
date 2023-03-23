#include "fdf.h"
#include <stdio.h>

int	main(void)
{
	fdf *data;
	int i = 0;
	int j = 0;

	data = (fdf*)malloc(sizeof(fdf));
	read_map("test_map", data);
	// printf("%i\n", get_height("test_map"));
	// printf("%i\n", get_weight("test_map"));
	printf("%i\n", data->height);
	printf("%i\n", data->weight);
	while(i < data->height)
	{
		while (j < data->weight)
			printf("%i ", data->z_map[i][j++]);
		printf("\n");
		i++;
	}
	return (0);
}