/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <lkah-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:57:49 by lkah-chu          #+#    #+#             */
/*   Updated: 2024/04/07 17:50:14 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    if(!str)
        return (0);
    while(str[i])
        i++;
    return (i);
}

char    *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    if(!s)
        return (NULL);
    if(c == '\0')
        return (s + ft_strlen(s));
    while(s[i])
    {
        if(s[i] == c)
            return (s + i);
        i++;
    }
    return(0);
}

char    *ft_strjoin()