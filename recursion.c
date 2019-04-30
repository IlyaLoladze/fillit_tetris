#include <stdio.h>
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define EMPTY_T '0'

char **g_map;

int g_map_size;

int g_count_f;

void	change_combination(t_term *figure, int *id_current, int *i, int *j)
{
	int i_last;
	int j_last;
	int tmp;
	t_term *last_felt;

	if (*id_current == 0) //не хватает размера
	{
		*i = 0;
		*j = 0;
		g_map_size++;
	}
	else //меняем комбинацию б.к.
	{
		tmp = -1;
		last_felt = figure + *id_current - 1;
		j_last = (last_felt->x)[0];
		i_last = (last_felt->y)[0];
		while (++tmp < 4)
			g_map[(last_felt->y)[tmp]][(last_felt->x)[tmp]] = EMPTY_T;
		*i = i_last;
		*j = j_last + 1; //начинаем со следующего базового квадрата
	}
}

void	fill_figure(t_term *figure, int id_current)
{
	int i;
	t_term *curr;

	curr = figure + id_current;
	i = -1;
	while (++i < 4)
		g_map[(curr->y)[i]][(curr->x)[i]] = 'A' + id_current;
}

void	fill_it(t_term *figure)
{
	static int id_current;
	static int i;
	static int j;

	if (id_current == g_count_f) //вписали все элементы ? хорош
		return ;
	if (j == g_map_size) //следующее id
	{
		j = 0;
		i++;
	}
	if (i == g_map_size) //не вписали все элементы и дошли до конца
	{
		change_combination(figure, &id_current, &i, &j);
		fill_it(figure);
	}
	if (g_map[i][j] == EMPTY_T && if_possible(g_map, g_map_size, figure + id_current, i, j))
	{
		fill_figure(figure, id_current);
		id_current++;
	}
	else if (++j > 0)
		fill_it(figure);
}

void	print_figure(t_term *figure)
{
	int i = -1;

	printf("\n\nPRINT FIGURE\n\n");
	while (++i < 4)
	{
		printf("x[%d] = %d; y[%d] = %d\n", i, figure->x[i], i, figure->y[i]);
	}
	printf("\n");
}

int     main(int argc, char **argv)
{
    int     fd;
    t_term  *data;
    char    *line;

    if (argc != 2)
    {
        ft_putendl("usage: fillit input_file");
        return (0);
    }
    fd = open(argv[1], O_RDONLY);
    if (!(data = (t_term *)malloc(sizeof(t_term) * 26)) ||
		!(line = ft_strnew(21)))
    {
        ft_putendl("error");
        return (0);
    }
    if (fd < 0 || ft_check_file(fd, line, data) != 0)
    {
		free(line);
        free(data);
        ft_putendl("error");
        return (0);
    }
	g_map = (char **)malloc(sizeof(char *) * 26);
	int i = 0;
	while (i < 26)
	{
		g_map[i] = (char *)malloc(sizeof(char) * 105);
		i++;
	}
	g_count_f = 2;
	g_map_size = 4;
	fill_it(data);
	free(line);
	close(fd);
	return (0);
}
