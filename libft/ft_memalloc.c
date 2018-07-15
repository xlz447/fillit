/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:46:22 by xzhu              #+#    #+#             */
/*   Updated: 2018/07/09 20:46:24 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *out;

	out = malloc(size);
	if (!out)
		return (NULL);
	else
	{
		bzero(out, size);
		return (out);
	}
}
