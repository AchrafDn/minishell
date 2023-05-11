#include "header.h"

int	main(void)
{
	t_vars vars;
    char *str;
	int i;

	i = 0;
	str = "< a > out >>her <<app|grepmi\"<|>>i\"vvs\"shell\"|-lawc\"|\"\"\"";
	create_2d_array(&vars, str);
	while (vars.ar_2d[i])
	{
		printf("%s\n", vars.ar_2d[i]);
		i++;
	}
	create_list(&vars);
	return (0);
}