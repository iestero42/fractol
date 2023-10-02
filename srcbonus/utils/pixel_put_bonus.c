/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:17:56 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/29 11:03:52 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief 
 * 
 * @param data 
 * @param x 
 * @param y 
 * @param color 
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int *)(data->addr + offset) = color;
}
