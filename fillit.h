/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:55:39 by smanhack          #+#    #+#             */
/*   Updated: 2019/05/06 18:12:41 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define EMPTY '.'
# include "libft/includes/libft.h"
# include <libc.h>

typedef	struct	s_term
{
	int			x[4];
	int			y[4];

}				t_term;

int				ft_check_file(int fd, char *line, t_term *data);

void			print_figure(t_term *figure);

int				is_fillable(t_term *figure, int size, char **map);

int				move_figure(t_term *figure, int i, int j);

void			ft_map_free(char ***map, int size);

char			**ft_map_create(int size);

char			**ft_map_updata(char ***map, int size);

int				ft_min_sqrt(int count);

void			print_answer(int map_size, char **map);

#endif
