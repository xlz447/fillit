/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:25:47 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/12 15:25:49 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkshape(char *buf)
{
	int c;
	int i;

	i = -1;
	c = 0;
	while (++i < 20)
	{
		if (buf[i] == '#')
		{
			if (i >= 1 && buf[i - 1] == '#')
				c++;
			if (i < 19 && buf[i + 1] == '#')
				c++;
			if (i >= 5 && buf[i - 5] == '#')
				c++;
			if (i < 15 && buf[i + 5] == '#')
				c++;
		}
	}
	if (c == 6 || c == 8)
		return (1);
	return (-1);
}

int		checktemino(char *buf)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (!(buf[i * 5 + j] == '.' || buf[i * 5 + j] == '#'))
				return (-1);
			if (buf[i * 5 + j] == '#')
				c++;
			j++;
		}
		if (buf[i * 5 + j] != '\n')
			return (-1);
		j = 0;
		i++;
	}
	if (c != 4)
		return (-1);
	return (1);
}

int		checkinput(char *buf)
{
	int		i;
	char	*temino;

	i = 0;
	temino = ft_strnew(20);
	while (i < 26)
	{
		ft_strncpy(temino, &(buf[i * 21]), 20);
		if (checktemino(temino) == -1 || checkshape(temino) == -1)
		{
			free(temino);
			return (-1);
		}
		i++;
		if (buf[i * 20 + (i - 1)] == '\0')
			break ;
	}
	free(temino);
	return (1);
}

char	**make2darray(char *buf, int *count)
{
	char	**to_ret;
	int		i;
	int		curr_ch;

	to_ret = (char**)ft_memalloc(27 * sizeof(*to_ret));
	i = 0;
	while (i < 26)
		to_ret[i++] = ft_strnew(16);
	i = -1;
	curr_ch = 0;
	while (buf[++i])
	{
		if (buf[i] != '\n')
		{
			if (buf[i] == '.')
				to_ret[curr_ch / 16][curr_ch % 16] = buf[i];
			else
				to_ret[curr_ch / 16][curr_ch % 16] = 'A' + ((curr_ch / 16));
			curr_ch++;
		}
	}
	*count = curr_ch / 16;
	return (to_ret);
}

int		main(int argc, char **argv)
{
	short	fd;
	short	rd;
	char	*buf;
	char	**twodshapes;
	int		count;

	if (argc != 2 || !argv[0])
		ft_errorexit("usage: fillit <filename>");
	buf = ft_strnew(555);
	count = 0;
	if ((fd = open(argv[1], O_RDONLY)) >= 0)
	{
		rd = read(fd, buf, 555);
		if (checkinput(buf) == 1)
		{
			twodshapes = make2darray(buf, &count);
			solve(twodshapes, count);
		}
		else
			ft_errorexit("error");
	}
	else
		ft_errorexit("error");
	return (1);
}
