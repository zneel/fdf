/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:01:20 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 09:02:02 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief 
 * @param mat Pointer to the t_matrix structure.
 * @param x The x-coordinate value.
 * @param y The y-coordinate value.
 * @return A pointer to the created t_vect3 structure,
	or NULL if memory allocation failed.
 */
t_vect3	*get_vect3(t_matrix *mat, int x, int y)
{
	t_vect3	*v3;

	v3 = malloc(sizeof(t_vect3));
	if (!v3)
		return (NULL);
	v3->x = x;
	v3->y = y;
	v3->z = mat->matrix[y][x];
	return (v3);
}
