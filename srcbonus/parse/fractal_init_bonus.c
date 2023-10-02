/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:37 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/02 11:17:16 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief 
 * 
 */
static void	mlx_error(char *msg_error)
{
	perror(msg_error);
	exit(EXIT_FAILURE);
}

/**
 * @brief 
 * 
 * @param fractol 
 */
static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 2;
	fractol->cmplx_precision = 42;
	fractol->zoom = 1.0;
	fractol->button_pressed = 0;
	fractol->info_frt.shift_x = 0.0;
	fractol->info_frt.shift_y = 0.0;
}

/**
 * @brief 
 * 
 * @param fractol 
 */
static void	event_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win, KEYPRESS, 1L << 0, key_handler, fractol);
	mlx_hook(fractol->mlx_win, DESTROYNOTIFY, 1L << 17, close_handler, fractol);
	mlx_hook(fractol->mlx_win, BUTTONPRESS, 1L << 2, mouse_handler, fractol);
	mlx_hook(fractol->mlx_win, BUTTONRELEASE, 1L << 3,
		mouse__release_handler, fractol);
	mlx_hook(fractol->mlx_win, MOTIONNOTIFY, 1L << 8, julia_track, fractol);
}

/**
 * @brief 
 * 
 * @param fractal 
 */
void	fractol_init(t_fractol *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		mlx_error("");
	fractal->mlx_win = mlx_new_window(fractal->mlx,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_win)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		mlx_error("");
	}
	fractal->img_data.img = mlx_new_image(fractal->mlx,
			WIDTH / 1.5, HEIGHT / 1.5);
	if (!fractal->img_data.img)
	{
		mlx_destroy_image(fractal->mlx, fractal->img_data.img);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		mlx_error("");
	}
	fractal->img_data.addr = mlx_get_data_addr(fractal->img_data.img,
			&fractal->img_data.bits_per_pixel,
			&fractal->img_data.line_length, &fractal->img_data.endian);
	data_init(fractal);
	event_init(fractal);
}
