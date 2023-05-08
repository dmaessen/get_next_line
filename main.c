/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:12:48 by dmaessen          #+#    #+#             */
/*   Updated: 2023/02/09 14:53:13 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

int main(void)
{
    char    *line;
    int     fd;
    // int     fd1;
    int     i;
    i = 1;
    fd = open("oneline.txt", O_RDONLY);
    // fd1 = open("test.txt", O_RDONLY);
    while (i < 10)
    {
        line = get_next_line(fd);
        printf("[%d] %s\n", i, line);
        free(line);
        // line = get_next_line(fd1);
        // printf("[%d] %s", i, line);
        // free(line);
        i++;
    }
    system("leaks -q a.out");
    close(fd);
    // close(fd1);
    return (0);
}