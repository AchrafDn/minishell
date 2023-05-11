#include "libft.h"

char	*ft_strdup(char *s1)
{
	size_t i;
	char *p;

	i = 0;
	p = (char *)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}