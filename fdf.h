#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
# include <fcntl.h>
#include "/Users/marihovh/Desktop/Fdf/libft/libft.h"

typedef struct
{
    int height;
    int weight;
    int **z_map;

    void *mlx_ptr;
    void *win_ptr;
}           fdf;

int get_height(char *fn);
char *get_next_line(int fd);
int	ft_word_cnt(char const *s, char c);
void    read_map(char *fn, fdf *data);
void    fill(int *zes, char *line);
int get_weight(char *fn);
int get_height(char *fn);

#endif