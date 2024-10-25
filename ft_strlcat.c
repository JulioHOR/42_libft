/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:22:41 by juhenriq          #+#    #+#             */
/*   Updated: 2024/10/25 19:52:37 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t strlcat(char *dst, const char *src, size_t size) {
	size_t dst_len = 0;
	size_t src_len = 0;

	// Calcula o comprimento de `dst` sem ultrapassar `size`
	while (dst_len < size && dst[dst_len] != '\0') {
		dst_len++;
	}

	// Calcula o comprimento de `src`
	while (src[src_len] != '\0') {
		src_len++;
	}

	// Se `dst` já é maior ou igual a `size`, significa que não há espaço para copiar nada de `src`
	if (dst_len == size) {
		return size + src_len;
	}

	// Copia `src` para `dst` respeitando o limite de `size`
	size_t i = 0;
	while (src[i] != '\0' && (dst_len + i) < (size - 1)) {
		dst[dst_len + i] = src[i];
		i++;
	}

	// Garante que `dst` seja nulo-terminada
	dst[dst_len + i] = '\0';

	// Retorna o comprimento total que `dst` teria se `size` fosse suficiente para toda a concatenação
	return dst_len + src_len;
}


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	while (dst[i] != '\0')
		i++;
	dst_size = i;
	i = 0;
	while (src[i] != '\0')
		i++;
	src_size = i;
	i = dst_size;
	j = 0;
	while ((i < (src_size - 1)) && ((i - 1) < size))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (src_size + dst_size);
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	expected_output[14];
	size_t	size_t_expected_output;
	char	our_output[14];
	size_t	size_t_our_output;
	
	char	src[] = "lorem ipsum dolor sit amet";
	size_t	size_t_param = 15;

	// void	*ft_memset(void *s, int c, size_t n)
	memset(expected_output, 'a', 1);
	memset(our_output, 'a', 1);
	
	size_t_expected_output = strlcat(expected_output, src, size_t_param);
	size_t_our_output = ft_strlcat(our_output, src, size_t_param);
	printf("Resultado esperado:\n%s\n%zu\n\n", expected_output, 
		size_t_expected_output);
	printf("Resultado obtido:\n%s\n%zu\n\n", our_output, 
		size_t_our_output);
	return (0);
}