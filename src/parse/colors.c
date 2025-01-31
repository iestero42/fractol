/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:02:25 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/10 10:57:29 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

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
 * @param i 
 * @param iterations 
 * @return int 
 */
int	interpolation(double t)
{
	int	raw_color;

	raw_color = create_trgb(0,
			(int)(9 * (1 - t) * t * t * t * 255),
			(int)(15 * (1 - t) * t * t * 150),
			(int)(8.5 * (1 - t) * t * 100));
	return (raw_color % WHITE);
}
