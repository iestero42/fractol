/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:15:38 by yunlovex          #+#    #+#             */
/*   Updated: 2023/09/18 11:22:21 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/**
 * @brief 
 * 
 */
# include "libft.h"
# include "keys.h"

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

# define WIDTH_FRACTAL 960
# define HEIGHT_FRACTAL 540

/**
 * @brief 
 * 
 */
# define ERROR_MESSAGE "FUCK"

/*
 * COLORS
*/
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x8000FF00  // RGB(0, 255, 0)
# define BLUE        0x2D8DA5  // RGB(0, 0, 255)
# define ORANGE		 0xFFA500
# define YELLOW 	 0xFFFF00
# define PINK		 0x871E72

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
typedef struct s_colors
{
	int				num_colors;
	unsigned int	array_color[4];
}	t_colors;

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
typedef struct s_info
{
	char		*name;
	t_complex	z;
	t_complex	(*ft)(struct s_complex, struct s_complex, void *param);
	double		power;
	double		shift_x;
	double      shift_y;
	
}	t_info;

/**
 * @brief 
 * 
 */
typedef struct s_fractol {
	char			*name;
	void			*mlx;
	void			*mlx_win;
	int				cmplx_precision;
	int				color_quality;
	int				button_pressed;
	double			zoom;
	double			escape_value;
	t_info			info_frt;
	t_data			img_data;
	t_colors		colors;
}	t_fractol;



int			ft_strcmp(char *s1, char *s2);

void		fractol_init(t_fractol *fractal);

double		map(double unscaled_num, double new_min, double new_max, double old_max);

t_complex	sum_complex(t_complex num1, t_complex num2);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

int			fractol_render(t_fractol *fractal);

int			create_trgb(int t, int r, int g, int b);

int			get_t(int trgb);

int			get_r(int trgb);

int			get_g(int trgb);

int			get_b(int trgb);

int			key_handler(int key, t_fractol *fractol);

int			mouse_handler(int button, int x, int y, t_fractol *fractol);

int			close_handler(t_fractol *fractol);

double		ft_atod(char *s);

unsigned long long int	binomialcoeff(int n, int k);

void		*choose_ft(t_fractol *fractol);

t_complex	mandelbrot(t_complex z, t_complex c, t_fractol *fractol);

t_complex	final_sum(t_complex z, t_complex c, t_fractol *fractol);

t_complex	polinomic_exp_ft(t_complex z, t_complex c, t_fractol *fractol);

t_complex	polinomic_sin_ft(t_complex z, t_complex c, t_fractol *fractol);

t_complex	z2_over_ln_z_ft(t_complex z, t_complex c, t_fractol *fractol);

t_complex	polinomic_sqrt_sinh_ft(t_complex z, t_complex c, t_fractol *fractol);

int			julia_track(int x, int y, t_fractol *fractal);

t_complex	power_complex(t_complex num, int n);

t_complex	divide_complex(t_complex a, t_complex b);

int			mouse__release_handler(int button, int x, int y, t_fractol *fractol);

#endif