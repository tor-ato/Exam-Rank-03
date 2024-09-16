/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:09:45 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/16 21:09:46 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char c;
    int read_size;
    char *str_bfr;
    int i = 0;
    

    if(fd < 0 || BUFFER_SIZE < 1)
        return NULL;

    read_size  = read(fd, &c, 1);
    str_bfr = (char *) malloc(42000000);

    while(read_size)
    {
        str_bfr[i] = c;
        i++;
        if (c == '\n' || c == EOF)
            break ;
        read_size = read(fd, &c, 1);
    }
    if (!read_size)
    {
        free(str_bfr);
        return NULL;
    }
    str_bfr[i] = 0;
    return str_bfr;
}

int main()
{
    char *a;
    int fd;
    
    fd  = open("test.txt", O_RDONLY);

    while(a = get_next_line(fd))
        printf("%s",a);
    close(fd);
}