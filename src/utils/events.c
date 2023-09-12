/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:32:50 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/12 11:52:47 by iestero-         ###   ########.fr       */
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
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * @param key 
 */
int	key_handler(int key, t_fractol *fractol)
{
	if (key == ESCAPE)
		close_handler(fractol);
	return (0);
}

/**
 * @brief 
 * 
 * @param key 
 * @param fractol 
 * @return int 
 */
int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	x = y;
	if (button == MOUSE_FWD)
		fractol->zoom *= 0.95;
	if (button == MOUSE_BCW)
		fractol->zoom *= 1.05;
	fractol_render(fractol);
	return (0);
}
