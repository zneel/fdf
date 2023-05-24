/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:38:29 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/24 17:18:19 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief Get the value row major order object
 * m[x][y] = base addr + sizeofint ((x - 0) * matrix.size_y + (y - 0)) 
 * @param mat 
 * @param x 
 * @param y 
 * @return int 
 */
int	get_value_row_major_order(t_matrix *mat, int x, int y)
{
	if ((x >= 0 && x < mat->size_x) && (y >= 0 && y < mat->size_y))
		return (mat->matrix[x * mat->size_y + y]);
	return (0);
}
