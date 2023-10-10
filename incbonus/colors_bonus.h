/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:05:10 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/10 11:04:09 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_BONUS_H
# define COLORS_BONUS_H

# include "structs_bonus.h"

/*
 * COLORS
*/
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)


int			create_trgb(int t, int r, int g, int b);

int			interpolation(double t, t_fractol *fractol);

void		change_color(t_fractol *fractol);

#endif