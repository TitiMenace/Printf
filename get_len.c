int	get_len(va_list args,  int j, char *str)
{
	int	i;
	char	*tmp;

	i = 0;
	if (str[j] == 'u')
	{
		tmp = ft_utoa(va_arg(args, int));
		while (tmp[i])
			i++;
		free(tmp);
		return (i);	
	}
	
	if (str[j] == 'd' || 'i')
	{
		tmp = ft_itoa(va_arg(args, int));
		while (tmp[i])
			i++;
		free(tmp);
		return (i);	
	}
	if (str[j] == 'c')
		return (1);
	if (str[j] == 's')
	{
		tmp = va_arg(args, char);
		while (tmp[i])
			i++;
		return (i);
	}
	if (str[j] == 'p')
	{
		tmp = putnbr_hexa(va_args, int);
		while (tmp[i])
			i++;
		return (i);
	}
	if (str[j] == 'x' || 'X')
		tmp = putnbr_hexa(va_args, int)
		while (tmp[i])
			i++;
		return (i);
	return (i);

}
