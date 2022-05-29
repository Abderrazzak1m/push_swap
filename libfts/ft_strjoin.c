/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:42:04 by amiski            #+#    #+#             */
/*   Updated: 2021/11/10 09:04:58 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libfts.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (char *)s1, len);
	ft_strlcat(str, (char *)s2, len);
	return (str);
}
