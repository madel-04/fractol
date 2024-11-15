/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:50:20 by marvin            #+#    #+#             */
/*   Updated: 2024/11/15 11:48:31 by marvin           ###   ########.fr       */
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

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

#define WIDTH 800
#define HEIGHT 800

// *** COLORS ***
// Colors in RGB format
#define COLOR_BLACK     0x000000  // Black: RGB(0, 0, 0)
#define COLOR_WHITE     0xFFFFFF  // White: RGB(255, 255, 255)
#define COLOR_RED       0xFF0000  // Red: RGB(255, 0, 0)
#define COLOR_GREEN     0x00FF00  // Green: RGB(0, 255, 0)
#define COLOR_BLUE      0x0000FF  // Blue: RGB(0, 0, 255)
#define COLOR_YELLOW    0xFFFF00  // Yellow: RGB(255, 255, 0)
#define COLOR_CYAN      0x00FFFF  // Cyan: RGB(0, 255, 255)
#define COLOR_MAGENTA   0xFF00FF  // Magenta: RGB(255, 0, 255)
#define COLOR_ORANGE    0xFFA500  // Orange: RGB(255, 165, 0)
#define COLOR_PURPLE    0x800080  // Purple: RGB(128, 0, 128)
#define COLOR_GRAY      0x808080  // Gray: RGB(128, 128, 128)
#define COLOR_DARK_GRAY 0x404040  // Dark Gray: RGB(64, 64, 64)
#define COLOR_LIGHT_GRAY 0xD3D3D3 // Light Gray: RGB(211, 211, 211)

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int	bpp;
	int	endian;
	int	line_len;
}		t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;


typedef struct	s_fractal
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
}		t_fractal;

// *** MATH_UTILS ***
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);

// *** STRINGS_UTILS ***
int     ft_strncmp(char *s1, char *s2, int n);
void    putstr_fd(char *s, int fd);
double	atodbl(char *s);

// *** RENDER ***
void	fractal_render(t_fractal *fractal);

// *** FACTAL_INIT ***
void	fractal_init(t_fractal *fractal);

// *** HANDLER ***
int	mouse_handler(int button, int x, int y, t_fractal *fractal);
int key_handler(int keysym, t_fractal *fractal);
// Clean-up;
int	close_handler(t_fractal *fractal);
int	julia_track(int x, int y, t_fractal *fractal);

#endif
