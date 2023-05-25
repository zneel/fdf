/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:38:29 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/25 22:47:34 by ebouvier         ###   ########.fr       */
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
