/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:47:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 12:47:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
/*
Dibuja un píxel en una posición específica dentro de la imagen con un color dado.
Escribe el color en la posición calculada usando un puntero al buffer de píxeles (img->pixels_ptr).
*/

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BABY_BLUE, LIGHT_CORAL, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;	
	}
	my_pixel_put(x, y, &fractal->img, LIGHT_CORAL);
}
/*
Propósito:
Calcula el color de un píxel en el fractal y lo dibuja en la imagen.
	Mapeo de coordenadas:
Mapea las coordenadas de la pantalla (x, y) al espacio complejo usando la función map:
Las coordenadas de la pantalla (x, y) están en un rango discreto [0, WIDTH] y [0, HEIGHT].
Se mapean al rango continuo del espacio complejo, en ambos ejes.
Aplica el zoom y desplazamiento (shift_x y shift_y) para permitir interactividad.
	Definición de c para Mandelbrot o Julia:
Llama a mandel_vs_julia para definir el valor inicial de c.
	Iteración del fractal:
Calcula el próximo valor de z usando las funciones de números complejos (square_complex y sum_complex).
Si el módulo cuadrado supera un umbral (escape_value), el punto escapa.
	Si el punto escapa:
		Mapea la cantidad de iteraciones a un color.
		Dibuja el píxel con ese color.
	Si no escapa después del máximo número de iteraciones (iterations_definition)
		colorea el píxel con un color predeterminado (LIGHT_CORAL).
*/

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);	

}
/*
Doble bucle para recorrer todos los pixeles por coordenadas y se usa la función
mlx_put_image_to_window para enviar la imagen generada a la ventana del programa
*/
