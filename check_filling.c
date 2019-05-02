/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:46:39 by tkarri            #+#    #+#             */
/*   Updated: 2019/05/02 19:10:34 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_record(t_term *figure, int size, char **map)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if ((figure->x)[i] >= size || (figure->y)[i] >= size
			|| (figure->x)[i] < 0 || (figure->y)[i] < 0
			|| map[(figure->y)[i]][(figure->x)[i]] != EMPTY)
			return (0);
	}
	return (1);
}

int		move_figure(t_term *figure, int i, int j)
{
	int change_i;
	int change_j;
	int diff_i;
	int diff_j;

	diff_i = i - (figure->y)[0];
	diff_j = j - (figure->x)[0];
	change_i = 0;
	change_j = -1;
	while (++change_i <= 2)
	{
		while (++change_j < 4)
		{
			if (change_i == 1)
				(figure->x)[change_j] += diff_j;
			else
				(figure->y)[change_j] += diff_i;
		}
		change_j = -1;
	}
	return (0);
}
