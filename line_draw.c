/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:50:17 by marihovh          #+#    #+#             */
/*   Updated: 2023/03/24 03:50:18 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int color(int z1, int z2)
{
    if (z1 == 0 && z2 == 0)
        return (0xffffff);
    if (z1 != 0 && z2 == 0)
        return (0xf00000);
    if (z1 == 0 && z2 != 0)
        return (0xf00000);
    if (z1 != 0 && z2 != 0)
        return (0xf00000);
    return (0);
}

void    line_draw(fdf *data, float x1, float y1, float x2, float y2)
{
    float   dx;
    float   dy;
    int     maxi;
    int     z1;
    int     z2;

    z1 = data->z_map[(int)y1][(int)x1];
    z2 = data->z_map[(int)y2][(int)x2];
    data->zoom = 30;
    y2 += 18;
    y1 += 18;
    x1 *= data->zoom;
    y1 *= data->zoom;
    x2 *= data->zoom;
    y2 *= data->zoom;
    dx = x2 - x1;
    dy = y2 - y1;
    maxi = fmax(fabsf(dx), fabsf(dy));
    dx /= maxi;
    dy /= maxi;
    while ((int)(x2 - x1) || (int)(y2 - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, color(z1, z2));
        x1 += dx;
        y1 += dy;
    }
}

void    draw_map(fdf *data)
{
    float   x;
    float   y;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->weight)
        {
            if (y < data->height - 1)
                line_draw(data, x, y, x, y + 1);
            if (x < data->weight - 1)
                line_draw(data, x, y, x + 1, y);
            x++;
        }
        y++;
    }
}