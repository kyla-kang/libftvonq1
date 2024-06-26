/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:43:38 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/23 14:43:40 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>//for va_*
# include <unistd.h>//for write

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_ptr(void *pointer);
int	print_dec(long long num);
int	print_hexa(unsigned long long num, int uppercase);
int	process_specifier(va_list *args, char spec);

#endif
