static void	check_#(int i, int j, char *str)
{
	int temp;
	
	temp = i;
	while (temp < j)
	{
		if (str[temp] == '#' && str[j] == 'x')
			write(1, "Ox", 2);
		if (str[temp] == '#' && str[j] == 'X')
			write(1, "0X", 2);
		i++;
	}
}

static void	check_+(int	i, int j, char *str)
{
	int temp;
	
	temp = i;
	while (temp < j)
	{
		if (str[temp] == '+' && (str[j] == 'd' || str[j] == 'i'))
			write(1, "+", 1);
		i++;
	}
}
static void	check_space(int i, int j, char *str)
{
	int temp;
	
	temp = i;
	while (temp < j)
	{
		if (str[temp] == ' ' && (str[j] == 'd' || str[j] == 'i'))
			write(1, " ", 1);
		i++;
	}
}

static void	check_width(int i, int j, char *str)
{
	
}
