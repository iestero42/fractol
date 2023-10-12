/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:15:45 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/12 10:53:22 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief 
 * 
 * @param fractal 
 * @param argv 
 */
static void	nova_init(t_fractol *fractal, char **argv)
{
	fractal->name = argv[1];
	fractal->info_frt.z.real = ft_atod(argv[2]);
	fractal->info_frt.z.img = ft_atod(argv[3]);
	fractal->info_frt.power = ft_atod(argv[4]);
}

/**
 * @brief 
 * 
 * @param fractal 
 * @param argv 
 */
static void	init_julia(t_fractol *fractal, char **argv)
{
	fractal->name = argv[1];
	fractal->info_frt.name = argv[2];
	fractal->info_frt.z.real = ft_atod(argv[3]);
	fractal->info_frt.z.img = ft_atod(argv[4]);
	fractal->info_frt.power = ft_atod(argv[5]);
}

int	main(int agc, char **argv)
{
	t_fractol	fractal;

	if (agc == 2 && (!ft_strcmp(argv[1], "mandelbrot")
			|| !ft_strcmp(argv[1], "nova")))
		fractal.name = argv[1];
	else if (agc == 6 && !ft_strcmp(argv[1], "julia"))
		init_julia(&fractal, argv);
	else if (agc == 5 && !ft_strcmp(argv[1], "nova"))
		nova_init(&fractal, argv);
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fractal.info_frt.ft = choose_ft(&fractal);
	fractol_init(&fractal);
	fractol_render(&fractal);
	mlx_loop(fractal.mlx);
}
