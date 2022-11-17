#include "../libft.h"

static void positifint(unsigned int n, int size)
{
	char	*dst;

	dst = NULL;
	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return ;
	dst[(size)] = '\0';
	size--;
	while (size > 0)
	{
		dst[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	dst[size] = n + '0';
    ft_putstr(dst);
    free(dst);
}

static int	get_size(int i)
{
	int	size;

	size = 0;
	while (i > 9)
	{
		i /= 10;
		size++;
	}
	return (size);
}

int ft_itoa_unsigned(unsigned int n)
{
	int					size;

	size = 1;
	size += get_size(n);
	positifint(n, size);
	return (size);
}
