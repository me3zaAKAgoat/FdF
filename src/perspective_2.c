/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:45:22 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/02 15:42:19 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_line(t_meta_data *fdf, int index)
{
	int	next_index;

	next_index = index + 1;
	if (fdf->points[next_index].x == (fdf->points[index].x + 1))
		bresenham(fdf,
			rotated_point(fdf, scaled_point(fdf, fdf->points[index])),
			rotated_point(fdf, scaled_point(fdf, fdf->points[next_index])));
}

void	draw_vertical_line(t_meta_data *fdf, int index)
{
	int	next_index;

	next_index = index + fdf->y_lengths_arr[fdf->points[index].y];
	if (next_index < fdf->nbr_of_points
		&& (fdf->points[index].x == fdf->points[next_index].x)
		&& (fdf->points[index].y + 1 == fdf->points[next_index].y))
		bresenham(fdf,
			rotated_point(fdf, scaled_point(fdf, fdf->points[index])),
			rotated_point(fdf, scaled_point(fdf, fdf->points[next_index])));
}

void	draw_frame(t_meta_data *fdf)
{
	int	index;

	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	index = 0;
	while (index < fdf->nbr_of_points)
	{
		draw_horizontal_line(fdf, index);
		index++;
	}
	index = 0;
	while (index < fdf->nbr_of_points)
	{
		draw_vertical_line(fdf, index);
		index++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	draw_menu(fdf);
}