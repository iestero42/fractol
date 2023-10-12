/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:15:38 by yunlovex          #+#    #+#             */
/*   Updated: 2023/10/12 11:53:40 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

/**
 * @brief 
 * 
 */
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "structs_bonus.h"
# include "events_bonus.h"
# include "math_bonus.h"
# include "colors_bonus.h"

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
# define WIDTH_FRACTAL	300
# define HEIGHT_FRACTAL	300

/**
 * @brief 
 * 
 */
# define ERROR_MESSAGE "\n usage: /fract-ol_bonus [set] [function] [real] [img] \n \
\t\t  [power]						  \n\n \
If the the set is mandelbrot, you must put the first parameter only. For example: \n \
\t -> /fract-ol mandelbrot \n\n \
If the set is julia, you must put all the parameters. For example: \n \
\t -> /fract-ol julia polinomic 0.2 0 2 \n\n \
The possible values for the function parameter are: \n \
\t -> polinomic \n \
\t -> polinomic-exp \n \
\t -> polinomic-sin \n "


void					fractol_init(t_fractol *fractal);

int						fractol_render(t_fractol *fractal);

void					fractal_render_img(t_fractol *fractal);

void					my_mlx_pixel_put(t_data *data, int x, int y, int color);

void					*choose_ft(t_fractol *fractol);

void					choose_fractal(t_complex *z, t_complex *c,
							t_fractol *fractal);

void					mlx_error(char *msg_error);

int						handle_pixel(int x, int y, t_fractol *fractal);

int						handle_pixel_nova(int x, int y, t_fractol *fractal);

#endif