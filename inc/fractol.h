/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:15:38 by yunlovex          #+#    #+#             */
/*   Updated: 2024/04/25 10:08:17 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/**
 * @brief 
 * 
 */
# include "libft.h"
# include "structs.h"
# include "events.h"
# include "colors.h"
# include "maths.h"

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
# define WIDTH_FRACTAL	250
# define HEIGHT_FRACTAL	250

/**
 * @brief 
 * 
 */
# define ERROR_MESSAGE "\n usage: /fractol [set] [function] [real] [img] \n \
\t\t  [power]						  \n\n \
If the the set is mandelbrot, you must put the first parameter only. For example: \n \
\t -> /fractol mandelbrot \n\n \
If the set is julia, you must put all the parameters. For example: \n \
\t -> /fractol julia polinomic 0.2 0 2 \n\n \
The possible values for the function parameter are: \n \
\t -> polinomic \n \
\t -> polinomic-exp \n \
\t -> polinomic-sin \n "

void					fractol_init(t_fractol *fractal);

int						fractol_render(t_fractol *fractal);

void					my_mlx_pixel_put(t_data *data, int x, int y, int color);

void					*choose_ft(t_fractol *fractol);

void					choose_fractal(t_complex *z, t_complex *c,
							t_fractol *fractal);

int						render_screenshot(t_fractol *fractal);

void					mlx_error(char *msg_error);

#endif