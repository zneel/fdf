/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:38:29 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 08:59:15 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_max(t_matrix *mat)
{
	int	max_value;
	int	current_value;
	int	i;
	int	j;

	i = 0;
	max_value = INT_MIN;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			current_value = mat->matrix[i][j];
			if (current_value > max_value)
				max_value = current_value;
			j++;
		}
		i++;
	}
	return (max_value);
}

int	get_min(t_matrix *mat)
{
	int	min_val;
	int	current_value;
	int	i;
	int	j;

	min_val = INT_MAX;
	i = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			current_value = mat->matrix[i][j];
			if (current_value < min_val)
				min_val = current_value;
			j++;
		}
		i++;
	}
	return (min_val);
}
