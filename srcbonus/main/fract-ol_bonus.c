/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:15:45 by iestero-          #+#    #+#             */
/*   Updated: 2024/04/25 10:32:14 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	check_digit(char *str)
{
	int	i;
	int	dot;

	i = -1;
	dot = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '.' && dot == 0)
		{
			dot = 1;
			continue ;
		}
		if (str[i] == '-' && i == 0 && str[i + 1] != '\0')
			continue ;
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * @param fractal 
 * @param argv 
 */
static void	nova_init(t_fractol *fractal, char **argv)
{
	fractal->name = argv[1];
	fractal->info_frt.power = ft_atoi(argv[2]);
	init_nova(fractal);
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
	else if (agc == 6 && !ft_strcmp(argv[1], "julia") && !check_digit(argv[3])
		&& !check_digit(argv[4]) && !check_digit(argv[5]))
		init_julia(&fractal, argv);
	else if (agc == 3 && !ft_strcmp(argv[1], "nova") && !check_digit(argv[2]))
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
