/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:54:10 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 12:54:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	if (old_max == 0)
	{
		fprintf(stderr, "Error: División por cero en map\n");
		exit(EXIT_FAILURE);
	}
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
}
/*
Escala un número desde un rango original (0 a old_max) a un nuevo 
rango (new_min a new_max).
*/

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
