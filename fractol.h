/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:50:20 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 13:00:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./a.out mandelbrot\"or \n\t\"./a.out julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

// *** COLORS ***
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define PASTEL_PINK         0xFFD1DC  // RGB(255, 209, 220)
# define LIGHT_CORAL         0xF08080  // RGB(240, 128, 128)
# define LIGHT_PEACH         0xFFDAB9  // RGB(255, 218, 185)
# define PALE_PINK           0xFADADD  // RGB(250, 218, 221)
# define PEACH               0xFFDAB9  // RGB(255, 218, 185)
# define PASTEL_YELLOW       0xFFFF99  // RGB(255, 255, 153)
# define LAVENDER_BLUSH      0xFFF0F5  // RGB(255, 240, 245)
# define LIGHT_LILAC         0xC8A2C8  // RGB(200, 162, 200)
# define CREAM               0xFFF5E1  // RGB(255, 245, 225)
# define MINT_GREEN          0x98FF98  // RGB(152, 255, 152)
# define PALE_TURQUOISE      0xAFEEEE  // RGB(175, 238, 238)
# define BABY_BLUE           0xBFEFFF  // RGB(191, 239, 255)
# define POWDER_BLUE         0xB0E0E6  // RGB(176, 224, 230)
# define LAVENDER            0xE6E6FA  // RGB(230, 230, 250)
# define PASTEL_BLUE         0xBFEFFF  // RGB(191, 239, 255)

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

// *** MATH_UTILS ***
double			map(double unscaled_num, double new_min, double new_max,
					double old_max);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);

// *** STRINGS_UTILS ***
int				ft_strncmp(char *s1, char *s2, int n);
void			putstr_fd(char *s, int fd);
double			atodbl(char *s);

// *** RENDER ***
void			fractal_render(t_fractal *fractal);

// *** FACTAL_INIT ***
void			fractal_init(t_fractal *fractal);

// *** HANDLER ***
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				key_handler(int keysym, t_fractal *fractal);
// Clean-up;
int				close_handler(t_fractal *fractal);
int				julia_track(int x, int y, t_fractal *fractal);

#endif
