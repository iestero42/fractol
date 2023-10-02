/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:15:38 by yunlovex          #+#    #+#             */
/*   Updated: 2023/10/02 11:33:31 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

/**
 * @brief 
 * 
 */
# include "libft.h"
# include "structs_bonus.h"
# include "events_bonus.h"
# include "complex_math_bonus.h"

/**
 * @brief 
 * 
 */
# include <mlx.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>

/**
 * @brief 
 * 
 */
# define WIDTH	1920
# define HEIGHT	1080

/**
 * @brief 
 * 
 */
# define BLACK       0x000000  
# define WHITE       0xFFFFFF

/**
 * @brief 
 * 
 */
# define ERROR_MESSAGE "\n usage: /fract-ol [set] [function] [real] [img] \n \
\t\t  [power]						  \n\n \
If the the set is mandelbrot, you only need to put the first parameter. For example: \n \
\t -> /fract-ol mandelbrot \n\n \
If the set is julia, you have to put all the parameters. For example: \n \
\t -> /fract-ol julia polinomic 0.2 0 2 \n\n \
The possible values for the function parameter are: \n \
\t -> polinomic \n \
\t -> polinomic-exp \n \
\t -> polinomic-sin \n "


void					fractol_init(t_fractol *fractal);

int						fractol_render(t_fractol *fractal);

double					map(double unscaled_num, double new_min,
							double new_max, double old_max);

void					my_mlx_pixel_put(t_data *data, int x, int y, int color);

int						ft_strcmp(char *s1, char *s2);

double					ft_atod(char *s);

unsigned long long int	binomialcoeff(int n, int k);

void					*choose_ft(t_fractol *fractol);



#endif