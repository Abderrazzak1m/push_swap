/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:55:47 by amiski            #+#    #+#             */
/*   Updated: 2021/11/14 00:15:39 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libfts.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
