/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:31:23 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/24 17:15:17 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	handle_directional_key_press(int key, double rota_unit,
		t_meta_data *fdf)
{
	if (key == KEY_LEFT)
		fdf->beta -= rota_unit;
	if (key == KEY_RIGHT)
		fdf->beta += rota_unit;
	if (key == KEY_UP)
		fdf->alpha += rota_unit;
	if (key == KEY_DOWN)
		fdf->alpha -= rota_unit;
	draw_frame(fdf);
}

void	handle_translation_key_press(int key, int translation_unit,
		t_meta_data *fdf)
{
	if (key == KEY_W)
		fdf->y_translation -= translation_unit;
	if (key == KEY_D)
		fdf->x_translation += translation_unit;
	if (key == KEY_S)
		fdf->y_translation += translation_unit;
	if (key == KEY_A)
		fdf->x_translation -= translation_unit;
	draw_frame(fdf);
}

int	handle_key_press(int key, t_meta_data *fdf)
{	
	double	rota_unit;
	int		translation_unit;

	rota_unit = 0.03;
	translation_unit = 30;
	if (key == KEY_ESC)
		return (handle_close_window(fdf), draw_frame(fdf), 0);
	if (key == KEY_ETR)
		return (set_base_perspective(fdf), draw_frame(fdf), 0);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
		return (handle_directional_key_press(key, rota_unit, fdf),
			draw_frame(fdf), 0);
	if (key == KEY_W || key == KEY_D || key == KEY_S || key == KEY_A)
		return (handle_translation_key_press(key, translation_unit, fdf),
			draw_frame(fdf), 0);
	if (key == KEY_T)
		return (fdf->z_scale_factor -= 0.03, draw_frame(fdf), 0);
	if (key == KEY_Y)
		return (fdf->z_scale_factor += 0.03, draw_frame(fdf), 0);
	return (0);
}

int	handle_zoom(int key, int x, int y, t_meta_data *fdf)
{	
	int	unit;

	x += 0;
	y += 0;
	unit = 1;
	if (key == ZOOM_OUT)
	{
		if (fdf->plane_scale_factor - unit > 0)
			return (fdf->plane_scale_factor -= unit, draw_frame(fdf), 0);
	}
	else if (key == ZOOM_IN)
		return (fdf->plane_scale_factor += unit, draw_frame(fdf), 0);
	return (0);
}
