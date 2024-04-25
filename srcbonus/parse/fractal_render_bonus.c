/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:53 by iestero-          #+#    #+#             */
/*   Updated: 2024/04/25 09:41:52 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief 
 * 
 * @param fractal 
 */
void	fractal_render_img(t_fractol *fractal)
{
	int		width;
	int		height;
	t_data	win;

	win.img = mlx_xpm_file_to_image(fractal->mlx, "./images/controls_bonus.xpm",
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
int	handle_pixel(int x, int y, t_fractol *fractal)
{
	t_complex		z;
	t_complex		c;
	unsigned int	i;
	int				color;

	z.real = (map(x, -2, +2, WIDTH_FRACTAL)
			* fractal->zoom) + fractal->info_frt.shift_x;
	z.img = (map(y, +2, -2, HEIGHT_FRACTAL)
			* fractal->zoom) + fractal->info_frt.shift_y;
	choose_fractal(&z, &c, fractal);
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = fractal->info_frt.ft(z, c, fractal);
		if (hypot(z.real, z.img) >= fractal->escape_value)
		{
			color = interpolation((double) i / fractal->cmplx_precision,
					fractal);
			return (color);
		}
	}
	return (BLACK);
}

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param fractal 
 */
int	handle_pixel_nova(int x, int y, t_fractol *fractal)
{
	t_complex		z;
	unsigned int	i;
	int				j;

	z.real = (map(x, -1, +1, WIDTH_FRACTAL)
			* fractal->zoom) + fractal->info_frt.shift_x;
	z.img = (map(y, +1, -1, HEIGHT_FRACTAL)
			* fractal->zoom) + fractal->info_frt.shift_y;
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = nova_ft(z, fractal);
		j = -1;
		while (++j < 3)
		{
			fractal->nova.diff.real = z.real - fractal->nova.roots[j].real;
			fractal->nova.diff.img = z.img - fractal->nova.roots[j].img;
			if (fabs(fractal->nova.diff.real) < 0.00001
				&& fabs(fractal->nova.diff.img) < 0.00001)
				return (interpolation((double) i / 100, fractal));
		}
	}
	return (BLACK);
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
	int	color;

	y = -1;
	color = 0;
	while (++y < HEIGHT_FRACTAL)
	{
		x = -1;
		while (++x < WIDTH_FRACTAL)
		{
			color = fractal->ft(x, y, fractal);
			my_mlx_pixel_put(&fractal->img_data, x, y, color);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img_data.img, 0, 0);
	return (0);
}
