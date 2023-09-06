/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:02:25 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/06 13:27:01 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
 * @brief Get the t object
 * 
 * @param trgb 
 * @return int 
 */
int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

/**
 * @brief Get the r object
 * 
 * @param trgb 
 * @return int 
 */
int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

/**
 * @brief Get the g object
 * 
 * @param trgb 
 * @return int 
 */
int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

/**
 * @brief Get the b object
 * 
 * @param trgb 
 * @return int 
 */
int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
