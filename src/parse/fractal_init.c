/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:37 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/01 12:41:57 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief 
 * 
 */
static void	mlx_error(char *msg_error, t_fractol *fractal)
{
	free(fractal);
	perror(msg_error);
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 2;
	fractol->iterations = 42;
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
		mlx_error("", fractal);
	fractal->mlx_win = mlx_new_window(fractal->mlx,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		mlx_error("", fractal);
	}
	fractal->img_data->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img_data->img)
	{
		mlx_destroy_image(fractal->mlx, fractal->img_data);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		mlx_error("", fractal);
	}
	fractal->img_data->addr = mlx_get_data_addr(fractal->img_data->img,
			fractal->img_data->bits_per_pixel,
			fractal->img_data->line_length, fractal->img_data->endian);
}
