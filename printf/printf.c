/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:28:09 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/16 18:31:49 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void put_str(char *str, int *len)
{
	if (!*str)
		str = "(null)";
	while(*str)
		*len += write(1, str++, 1);
}

void put_nbr(long long  number, int base,int *len)
{
	if (number < 0)
	{
		*len += write(1, "-", 1);
		number *= -1;
	}
	if (number > 0 && number > base)
		put_nbr(number / base, base , len);
	*len += write(1, &"0123456789abcdef"[number % base], 1);
}


int ft_printf(const char * format, ... )
{
	va_list ap;

	va_start(ap, format);
	int len = 0;

	while(*format)
	{
		if(*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ap, char *), &len);
			else if (*format == 'd')
				put_nbr((long long)va_arg(ap, int), 10, &len);
			else if (*format == 'x')
				put_nbr((unsigned long long)va_arg(ap,unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return len;
}

#include <stdio.h>


int main ()
{
	int ft_len = 0;
	int or_len = 0;


	// ft_len = ft_printf("%s\n","toto");
	// or_len = printf("%s\n","toto");
	// printf("ft_len = %d:\n",ft_len);
	// printf("or_len = %d:\n",or_len);


	
	// ft_len = ft_printf("Magic %s is %d\n", "number", 4233);
	// or_len = printf("Magic %s is %d\n", "number", 4233);
	// printf("ft_len = %d:\n",ft_len);
	// printf("or_len = %d:\n",or_len);


	
	ft_len = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	or_len = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("ft_len = %d:\n",ft_len);
	printf("or_len = %d:\n",or_len);
}
