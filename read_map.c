/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:49:59 by marihovh          #+#    #+#             */
/*   Updated: 2023/03/24 03:50:04 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_height(char *fn)
{
    int height;
    int fd;

    fd = open(fn, O_RDONLY);
    printf("%i", fd);
    height = 0;
    while (get_next_line(fd))
        height++;
    close(fd);
    return (height);
}

int get_weight(char *fn)
{
    int fd;
    char *line;
    int weight;

    fd = open(fn, O_RDONLY);
    line = get_next_line(fd);
    weight = ft_word_cnt(line, ' ');
    close(fd);
    return (weight);
}

void    fill(int *zes, char *line)
{
    char **splited;
    int     i;

    splited = ft_split(line, ' ');
    i = 0;
    while (splited[i])
    {
        zes[i] = ft_atoi(splited[i]);
        i++;
    }
    free(splited);
}

void    read_map(char *fn, fdf *data)
{
    int fd;
    int i;
    char *line;

    data->weight = get_weight(fn);
    data->height = get_height(fn);
    data->z_map = (int **)malloc(sizeof(int*) * (data->weight + 1));
    i = 0;
    while (i <= data->height)
        data->z_map[i++] = (int *)malloc(sizeof(int) * (data->weight + 1));
    fd = open(fn, O_RDONLY);
    i = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        fill(data->z_map[i], line);
        i++;
    }
    close(fd);
}
