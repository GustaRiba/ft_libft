
#include "libft.h"

int	main(void)
{
	int		index;
	char	**split;

	split = ft_split("a bb c dd ", ' ');
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}