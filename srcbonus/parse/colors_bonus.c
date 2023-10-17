/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:02:25 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/17 10:11:46 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief Create a trgb object
 * 
 * @param t 
 * @param r 
 * @param g 
 * @param b 
 * @return int 
 */
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief 
 * 
 * @param color 
 */
static void	init_color(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
		color[i++] = 0;
}

/**
 * @brief 
 * 
 * @param fractol 
 */
void	change_color(t_fractol *fractol)
{
	char	*line;
	int		color[3];
	int		i;

	ft_printf("PUT COLOR COMPONENTS:\n");
	init_color(color);
	i = -1;
	while (++i < 3)
	{
		line = get_next_line(STDIN_FILENO);
		color[i] = ft_atoi(line);
		free(line);
		if (color[i] < 0 || color[i] > 255)
		{
			ft_printf("ERROR: Invalid color");
			color[i] = 0;
			break ;
		}
	}
	fractol->colors.r = color[0];
	fractol->colors.g = color[1];
	fractol->colors.b = color[2];
	ft_printf("COLORS:\n RED => %i\n GREEN => %i\n BLUE => %i\n",
		fractol->colors.r, fractol->colors.g, fractol->colors.b);
}

/**
 * @brief
 * 
 * @param i 
 * @param iterations 
 * @return int 
 */
int	interpolation(double t, t_fractol *fractal)
{
	int	raw_color;

	raw_color = create_trgb(0,
			(int)(9 * (1 - t) * t * t * t * fractal->colors.r),
			(int)(15 * (1 - t) * t * t * fractal->colors.g),
			(int)(8.5 * (1 - t) * t * fractal->colors.b));
	return (raw_color % 0xFFFFFF);
}
