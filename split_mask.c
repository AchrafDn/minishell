#include "header.h"

char	*create_mask(char *str)
{
	int		i;
	char	*mask;

	i = 0;
	mask = malloc((sizeof(char) + 1) * ft_strlen(str));
	if (!mask)
		exit(1);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			mask[i] = '0';
		else if (str[i] == '|')
			mask[i] = '3';
		else if (str[i] == '<' || str[i] == '>')
			mask[i] = '2';
		else if (str[i] == '"')
		{
			mask[i] = '1';
			i++;
			while (str[i] && str[i] != '"')
			{
				mask[i] = '1';
				i++;
			}
			mask[i] = '1';
		}
		else
			mask[i] = '1';
		i++;
	}
	mask[i] = '\0';
	return (mask);
}

int	n_word(char *str)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '1')
		{
			while (str[i + j] && str[i + j] == '1')
				j++;
		}
		else if (str[i] == '2')
		{
			while (str[i + j] && str[i + j] == '2')
				j++;
		}
		else if (str[i] == '3')
			j++;
		else
			i++;
		if (j != 0)
		{
			word++;
			i += j;
		}
	}
	return (word);
}

char	**create_2d_array(char **array_2d, char *str, char *mask)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (mask[i])
	{
		j = 0;
		if (mask[i] == '1')
		{
			while (mask[i + j] && mask[i + j] == '1')
				j++;
		}
		else if (mask[i] == '2')
		{
			while (mask[i + j] && mask[i + j] == '2')
				j++;
		}
		else if (mask[i] == '3')
			j++;
		else
			i++;
		if (j != 0)
		{
			array_2d[x] = malloc(sizeof(char) * (j + 1));
			if (!array_2d[x])
				exit(1);
			array_2d[x] = ft_substr(str, i, j);
			i += j;
			x++;
		}
	}
	array_2d[x] = NULL;
	return (array_2d);
}

int	main(void)
{
	t_args 	cmd;
	t_cmd 	p;
	char	**array_2d;
	char	*str;
	char	*mask;

	str = "ls -la >>| grep mi\"<>|>i\"\"shell\" -la | wc \"\" \"\"  ";
	mask = create_mask(str);
	array_2d = malloc((sizeof(char *) + 1) * n_word(mask));
	if (!array_2d)
		exit(1);
	int i = 0;
	cmd.number_cmd = 0;
	create_2d_array(array_2d, str, mask);
	while (array_2d[i])
	{
		if (array_2d[i][0] == '|')
			cmd.number_cmd++;
		i++;
	}
	printf("%i\n", cmd.number_cmd);
	create_list(&p, array_2d);
}