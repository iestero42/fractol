/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:02:25 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/03 11:29:03 by iestero-         ###   ########.fr       */
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

static void	init_color(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
		color[i++] = 0;
}

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
