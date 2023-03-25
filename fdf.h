/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:49:50 by marihovh          #+#    #+#             */
/*   Updated: 2023/03/24 03:49:52 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "/Users/marihovh/Desktop/Fdf/libft/libft.h"
# include <stdio.h>

typedef struct
{
    int height;
    int weight;
    int **z_map;
    int zoom;

    void *mlx_ptr;
    void *win_ptr;
}           fdf;



int     get_height(char *fn);
char    *get_next_line(int fd);
int     ft_word_cnt(char const *s, char c);
void    read_map(char *fn, fdf *data);
void    fill(int *zes, char *line);
int     get_weight(char *fn);
void    line_draw(fdf *data, float x1, float y1, float x2, float y2);
void    draw_map(fdf *data);

#endif
