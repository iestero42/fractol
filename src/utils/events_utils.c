/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:33:58 by iestero-          #+#    #+#             */
/*   Updated: 2024/04/25 09:21:55 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	exit(EXIT_SUCCESS);
}

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
		mlx_error("mlx_new_image");
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
static void	handle_pixel(int x, int y, t_fractol *fractal, t_data *img)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = map(x, -2, +2, WIDTH / 1.5) * fractal->zoom;
	z.img = map(y, +1.3, -1.3, HEIGHT / 1.5) * fractal->zoom;
	choose_fractal(&z, &c, fractal);
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = fractal->info_frt.ft(z, c, fractal);
		if (hypot(z.real, z.img) >= fractal->escape_value)
		{
			color = interpolation((double) i / fractal->cmplx_precision);
			my_mlx_pixel_put(img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(img, x, y, BLACK);
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
	t_data	img;

	img = img_init(fractal);
	y = -1;
	while (++y < HEIGHT / 1.5)
	{
		x = -1;
		while (++x < WIDTH / 1.5)
			handle_pixel(x, y, fractal, &img);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win_prnt,
		img.img, (WIDTH - (WIDTH / 1.5)) / 20,
		(HEIGHT - (HEIGHT / 1.5)) / 2);
	mlx_destroy_image(fractal->mlx, img.img);
	return (0);
}
