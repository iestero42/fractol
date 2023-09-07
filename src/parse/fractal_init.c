/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:37 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/07 11:54:17 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
static void	colors_init(t_fractol *fractol)
{
	fractol->colors.num_colors = 3;
	fractol->colors.array_color[0] = BLACK;
	fractol->colors.array_color[1] = LAVA_RED;
	fractol->colors.array_color[2] = YELLOW;
}

/**
 * @brief 
 * 
 * @param fractol 
 */
static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 2;
	fractol->cmplx_precision = 50;
	fractol->color_quality = 35;
	colors_init(fractol);
}

/**
 * @brief 
 * 
 * @param fractol 
 */
static void	event_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win, KEYPRESS, 1L << 0, key_handler, fractol);
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
	fractal->img_data.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
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
