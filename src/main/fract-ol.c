/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:15:45 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/01 12:39:05 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int agc, char **argv)
{
	t_fractol	*fractal;

	
	if (agc == 2 && !ft_strcmp(argv[1], "mandelbrot")
		&& !ft_strcmp(argv[1], "julia"))
	{
		fractal = (t_fractol *) malloc(sizeof(fractal));
		if (!fractal)
			perror("Error");
		fractal->name = argv[1];
		fractol_init(fractal);
		fractol_render(fractal);
		mlx_loop(fractal->mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
