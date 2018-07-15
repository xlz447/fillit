/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:25:59 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/12 15:26:00 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int	g_res;

char		**emptymap(int const size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = NULL;
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[i][size] = '\0';
	}
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
	}
	return (map);
}

void	freemap(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
	map = NULL;
}


void	rmshape(char **m, char index, int s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < s)
	{
		while (j < s)
		{
			if (m[i][j] == 'A' + index)
				m[i][j] = '.';
				j++;
		}
		i++;
	}
}

int		tryshape(char *sh, char **m, int mc)
{
	int i;
	int fp;
	int s;
	//printf("Trying in %s in pos %i\n", sh, mc);
	fp = 0;
	s = ft_strlen(m[0]);
	while (sh[fp] == '.')
		fp++;
	i = 0;
	while (i < 16)
	{
		if (sh[i] != '.')
		{
			//printf("i = %i\n", i);
			//printf("x: %i, y: %i\n", mc / s + i / 4 - fp / 4, mc % s + i % 4 - fp % 4);
			if (mc / s + i / 4 - fp / 4 >= s ||
				mc % s + i % 4 - fp % 4 >= s ||
				m[mc / s + i / 4 - fp / 4][mc % s + i % 4 - fp % 4] != '.')
			{
				//printf("FAILED\n");
				return (0);
			}
		}
		i++;
	}
	i = 0;
	while (sh[i])
	{
		if (sh[i] != '.')
			m[mc / s + i / 4 - fp / 4][mc % s + i % 4 - fp % 4] = sh[i];
		i++;
	}
	return (1);
}

void		trymap(char **shapes, char **map, int pindex, int shapecount)
{
	int	mapcoor;
	int mapsize;

	mapsize = ft_strlen(map[0]);
	mapcoor = 0;
	while (mapcoor < mapsize * mapsize)
	{
		if (tryshape(shapes[pindex], map, mapcoor) == 1) // if i can put in this piece
		{
			//printf("\nPut in %i in pos %i\n", pindex, mapcoor);
			if (pindex != shapecount - 1)// if not last piece, put in current piece and try the next piece
				trymap(shapes, map, pindex + 1, shapecount);
			else
			{
				g_res = 1;
			}
		}
		if (g_res)
			return ;
		mapcoor++; // if cannot fit in try next coordinate
	}
	rmshape(map, pindex, mapsize);
}

void	solve(char **shapes, int shapecount)
{
	char	**map;
	int		mapsize;
	int		i;

	mapsize = 2;
	while (mapsize * mapsize < shapecount * 4)
		mapsize++;
	g_res = 0;
	while (42)
	{
		map = emptymap(mapsize);
		trymap(shapes, map, 0, shapecount);
		if (g_res)
			break ;
		freemap(map, mapsize);
		mapsize++;
	}
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}
