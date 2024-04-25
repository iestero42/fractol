/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:53 by iestero-          #+#    #+#             */
/*   Updated: 2024/04/25 09:22:58 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief 
 * 
 * @param fractal 
 */
static void	fractal_render_img(t_fractol *fractal)
{
	int		width;
	int		height;
	t_data	win;

	win.img = mlx_xpm_file_to_image(fractal->mlx, "./images/controls.xpm",
			&width, &height);
	win.addr = mlx_get_data_addr(win.img,
			&win.bits_per_pixel,
			&win.line_length, &win.endian);
	if (!win.addr)
		mlx_error("mlx_get_data_addr");
	mlx_put_image_to_window(fractal->mlx, fractal->win_prnt, win.img,
		1300, 0);
	mlx_destroy_image(fractal->mlx, win.img);
}

/**
 * @brief 
 * 
 * @param z 
 * @param c 
 * @param fractal 
 */
void	choose_fractal(t_complex *z, t_complex *c, t_fractol *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->real = fractal->info_frt.z.real;
		c->img = fractal->info_frt.z.img;
	}
	else
	{
		c->real = z->real;
		c->img = z->img;
	}
}

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param fractal 
 */
static void	handle_pixel(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = map(x, -2, +2, WIDTH_FRACTAL) * fractal->zoom;
	z.img = map(y, +2, -2, HEIGHT_FRACTAL) * fractal->zoom;
	choose_fractal(&z, &c, fractal);
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = fractal->info_frt.ft(z, c, fractal);
		if (hypot(z.real, z.img) >= fractal->escape_value)
		{
			color = interpolation((double) i / fractal->cmplx_precision);
			my_mlx_pixel_put(&fractal->img_data, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->img_data, x, y, BLACK);
}

/**
 * @brief 
 * 
 * @param fractal 
 */
int	fractol_render(t_fractol *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT_FRACTAL)
	{
		x = -1;
		while (++x < WIDTH_FRACTAL)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img_data.img, 0, 0);
	fractal_render_img(fractal);
	return (0);
}
