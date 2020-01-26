#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_BUFF_SIZE 500

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putchar((n % 10) + '0');
	ft_putnbr(n / 10);
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	ft_getchar()
{
	char c;

	read(0, &c, 1);
	if (c)
		return (c);
	return ('\0');
}

void	ft_getstr(char *str)
{
	char c;
	int i;

	i = 0;
	c = ft_getchar();
       	while (c != '\n')
	{
		str[i] = c;
		i++;
		c = ft_getchar();
	}	
	str[i] = '\0';
}

int	det_rush(char *line, int size)
{
	if (line[0] == 'o' && line[size - 1]  == 'o')
		return (1);
	else if (line[0] == '/' && line[size - 1] == '\\')
		return (2);
	else if (line[0] == 'A' && line[size - 1] == 'A')
		return (3);
	else if (line[0] == 'A' && line[size - 1] == 'C')
		return (4);
	else
		return (0);
}

int	is_rush(char *line, int size)
{
	int i;

	i = 1;
	while (i < size && (i + 1) < (size - 1))
	{	
		if (line[i] != line[i + 1])
			return (0);
		i++;
	}
	return (det_rush(line, size));
}

int	main()
{
	char line[MAX_BUFF_SIZE];

	ft_getstr(line);
	
	if (is_rush(line, ft_strlen(line)))
		ft_putstr(line);
	else
		ft_putstr("Not a rush");
	ft_putchar('\n');
	return (0);
}

