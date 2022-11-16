#include "../libft.h"

static char	*positifint(unsigned int n, int size)
{
	char	*dst;

	dst = NULL;
	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return (0);
	dst[(size)] = '\0';
	size--;
	while (size > 0)
	{
		dst[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	dst[size] = n + '0';
	return (dst);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int					size;
	unsigned int		i;

	size = 1;
	i = n;
	while (i > 9)
	{
		i /= 10;
		size++;
	}
	return (positifint(n, size));
}
