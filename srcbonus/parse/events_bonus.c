/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:32:50 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/10 10:48:17 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief 
 * 
 * @param key 
 */
int	key_handler_win2(int key, t_fractol *fractol)
{
	if (key == ESCAPE)
		close_handler(fractol);
	return (0);
}

/**
 * @brief 
 * 
 * @param key 
 */
int	key_handler(int key, t_fractol *fractol)
{
	if (key == ESCAPE)
		close_handler(fractol);
	else if (key == PLUS)
		fractol->cmplx_precision += 1;
	else if (key == MINUS)
		fractol->cmplx_precision -= 1;
	else if (key == ARROW_U)
		fractol->info_frt.shift_y += (0.5 * fractol->zoom);
	else if (key == ARROW_D)
		fractol->info_frt.shift_y -= (0.5 * fractol->zoom);
	else if (key == ARROW_L)
		fractol->info_frt.shift_x -= (0.5 * fractol->zoom);
	else if (key == ARROW_R)
		fractol->info_frt.shift_x += (0.5 * fractol->zoom);
	else if (key == ENTER)
		change_color(fractol);
	else if (key == LTR_P)
	{
		render_screenshot(fractol);
		return (0);
	}
	fractol_render(fractol);
	return (0);
}

/**
 * @brief 
 * 
 * @param key 
 * @param fractol 
 * @return int 
 */
int	mouse_handler(int button, int x, int y, struct s_fractol *fractol)
{
	int	original_x;
	int	original_y;

	original_y = y;
	original_x = x;
	x = original_x;
	y = original_y;
	if (button == MOUSE_FWD)
		sum_shift(0.95, x, y, fractol);
	else if (button == MOUSE_BCW)
		sum_shift(1.05, x, y, fractol);
	else if (button == MOUSE_L)
		fractol->button_pressed = 1;
	fractol_render(fractol);
	return (0);
}

/**
 * @brief 
 * 
 * @param button 
 * @param x 
 * @param y 
 * @param fractol 
 * @return int 
 */
int	mouse__release_handler(int button, int x, int y, t_fractol *fractol)
{
	x = y;
	if (button == MOUSE_L)
		fractol->button_pressed = 0;
	fractol_render(fractol);
	return (0);
}

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param fractal 
 * @return int 
 */
int	julia_track(int x, int y, struct s_fractol *fractal)
{
	x = y;
	if (!ft_strcmp(fractal->name, "julia") && fractal->button_pressed)
	{
		fractal->info_frt.z.real = (map(x, -2, +2, WIDTH_FRACTAL)
				* fractal->zoom) + fractal->info_frt.shift_x;
		fractal->info_frt.z.img = (map(y, +2, -2, HEIGHT_FRACTAL)
				* fractal->zoom) + fractal->info_frt.shift_y;
		fractol_render(fractal);
	}
	return (0);
}
