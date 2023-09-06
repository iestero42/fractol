/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:15:38 by yunlovex          #+#    #+#             */
/*   Updated: 2023/09/06 13:11:40 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/**
 * @brief 
 * 
 */
# include "libft.h"

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
# define WIDTH	1080
# define HEIGHT	800

/**
 * @brief 
 * 
 */
# define ERROR_MESSAGE "FUCK"

/*
 * COLORS
*/
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0x80FFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x8000FF00  // RGB(0, 255, 0)
# define BLUE        0x800000FF  // RGB(0, 0, 255)
# define ORANGE		 0xFFA500
# define YELLOW 	 0xFFFF00

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0x50FF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red

/**
 * @brief 
 * 
 */
typedef struct s_interval
{
	double	min;
	double	max;
}	t_interval;

/**
 * @brief 
 * 
 */
typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

/**
 * @brief 
 * 
 */
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/**
 * @brief 
 * 
 */
typedef struct s_fractol {
	char			*name;
	void			*mlx;
	void			*mlx_win;
	double			escape_value;
	int				iterations;
	t_data			img_data;
}	t_fractol;

int			ft_strcmp(char *s1, char *s2);

void		fractol_init(t_fractol *fractal);

t_interval	create_interval(int min, int max);

double		map(double unscaled_num, t_interval new, t_interval old);

t_complex	sum_complex(t_complex num1, t_complex num2);

t_complex	sqrt_complex(t_complex num);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

void		fractol_render(t_fractol *fractal);

int			create_trgb(int t, int r, int g, int b);

int			get_t(int trgb);

int			get_r(int trgb);

int			get_g(int trgb);

int			get_b(int trgb);

#endif