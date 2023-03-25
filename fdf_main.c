/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:05:33 by marihovh          #+#    #+#             */
/*   Updated: 2023/03/24 04:05:34 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	read_map("test_map", data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1600, 1000, "che lurj?");
	draw_map(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
