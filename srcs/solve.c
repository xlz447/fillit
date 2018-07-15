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

char		**new_map(int const size)
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
}

int		trymap(char **shapes, char **map, int c)
{
	return (1);
}

void	solve(char **shapes, int c)
{
	char	**map;
	int		mapsize;
	int		i;

	mapsize = 2;
	while (mapsize * mapsize < c * 4)
		mapsize++;

	while (42)
	{
		map = emptymap(mapsize);
		if (trymap(shapes, map, c))
			break ;
		freemap(map);
	}

	i = 0;
	while (solution[i])
		ft_putstr(solution[i++]);
}
