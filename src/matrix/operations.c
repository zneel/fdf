/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:38:29 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/26 22:24:50 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief Get the value row major order object
 * m[x][y] = base addr + sizeofint ((x - 0) * matrix.height + (y - 0)) 
 * @param mat 
 * @param x 
 * @param y 
 * @return int 
 */
int	get_value_row_major_order(t_matrix *mat, int x, int y)
{
	if ((x >= 0 && x < mat->width) && (y >= 0 && y < mat->height))
		return (mat->matrix[x * mat->height + y]);
	return (0);
}

int	get_maximum_value(t_matrix *mat)
{
	int	max_value = INT_MIN;
	int	i, j;

	for (i = 0; i < mat->width; i++)
	{
		for (j = 0; j < mat->height; j++)
		{
			int current_value = get_value_row_major_order(mat, i, j);
			if (current_value > max_value)
				max_value = current_value;
		}
	}
	return (max_value);
}