/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:12:23 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/01 19:14:56 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int main()
{
    char **s;
    int i;

    i = 0;
    s = malloc(sizeof(char *) * 10);
    while(i != 10)
    {
        s[i] = malloc(sizeof(char) * 10);
        i++;
    }
    printf (">%c<", s[3][4]);
    return 0;
}