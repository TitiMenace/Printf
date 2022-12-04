int	nb_len(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n / 10;
		count++;
	}
	return (count);
}


int	get_len(va_list args,  int *j, char *str)
{
	int	i;
	char	*tmp;

	i = 0;
	if (str[*j] == 'u')
		return (nb_len((int)va_arg(args, unsigned int)));
	if (str[*j] == 'd' || 'i')
		return (nb_len(va_arg(args, int)));
	if (str[*j] == 'c')
		return (1);
	if (str[*j] == 's')
		return (ft_strlen(va_args(args, char)));
	if (str[*j] == 'p')
	{
		tmp = putnbr_hexa(va_args, int);
		while (tmp[i])
			i++;
		return (i);
	}
	if (str[*j] == 'x' || 'X')
		tmp = putnbr_hexa(va_args, int)
		while (tmp[i])
			i++;
		return (i);
	return (i);

}
