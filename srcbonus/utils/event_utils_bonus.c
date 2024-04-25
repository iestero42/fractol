/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:06:21 by iestero-          #+#    #+#             */
/*   Updated: 2024/04/25 10:07:20 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief 
 * 
 * @param fractol 
 */
int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx,
		fractol->img_data.img);
	mlx_destroy_window(fractol->mlx,
		fractol->mlx_win);
	mlx_destroy_window(fractol->mlx,
		fractol->win_prnt);
	if (!ft_strcmp(fractol->name, "nova"))
		free(fractol->nova.roots);
	exit(EXIT_SUCCESS);
}

void	sum_shift(double zoom, int x, int y, t_fractol *fractol)
{
	fractol->zoom *= zoom;
	fractol->info_frt.shift_x += (map(x, -2.0, +2.0, WIDTH_FRACTAL)
			* fractol->zoom) * 0.1995;
	fractol->info_frt.shift_y += (map(y, +2, -2, HEIGHT_FRACTAL)
			* fractol->zoom) * 0.1995;
}

/**
 * @brief 
 * 
 * @param fractal 
 * @return t_data 
 */
static t_data	img_init(t_fractol *fractal)
{
	t_data	img;

	img.img = mlx_new_image(fractal->mlx,
			WIDTH / 1.5, HEIGHT / 1.5);
	if (!img.img)
	{
		mlx_destroy_image(fractal->mlx, img.img);
		mlx_destroy_image(fractal->mlx, fractal->img_data.img);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		mlx_destroy_window(fractal->mlx, fractal->win_prnt);
		free(fractal->mlx);
		mlx_error("");
	}
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.line_length, &img.endian);
	if (!img.addr)
		mlx_error("mlx_get_data_addr");
	return (img);
}

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param fractal 
 */
static int	handle_pixel_scr(int x, int y, t_fractol *fractal)
{
	t_complex		z;
	t_complex		c;
	unsigned int	i;

	z.real = (map(x, -2, +2, WIDTH / 1.5)
			* fractal->zoom) + fractal->info_frt.shift_x;
	z.img = (map(y, +1.3, -1.3, HEIGHT / 1.5)
			* fractal->zoom) + fractal->info_frt.shift_y;
	choose_fractal(&z, &c, fractal);
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = fractal->info_frt.ft(z, c, fractal);
		if (hypot(z.real, z.img) >= fractal->escape_value)
			return (interpolation((double) i / fractal->cmplx_precision,
					fractal));
	}
	return (BLACK);
}

/**
 * @brief 
 * 
 * @param fractal 
 */
int	render_screenshot(t_fractol *fractal)
{
	int		x;
	int		y;
	int		color;
	t_data	img;

	img = img_init(fractal);
	y = -1;
	while (++y < HEIGHT / 1.5)
	{
		x = -1;
		while (++x < WIDTH / 1.5)
		{
			if (!ft_strcmp(fractal->name, "nova"))
				color = handle_pixel_nova_scr(x, y, fractal);
			else
				color = handle_pixel_scr(x, y, fractal);
			my_mlx_pixel_put(&img, x, y, color);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win_prnt,
		img.img, (WIDTH - (WIDTH / 1.5)) / 20,
		(HEIGHT - (HEIGHT / 1.5)) / 2);
	mlx_destroy_image(fractal->mlx, img.img);
	return (0);
}
