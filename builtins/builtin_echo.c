/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:13:02 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/09/13 10:30:35 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_n(char *str)
{
	int	index;

	index = 2;
	if (str[0] == '-' && str[1] == 'n')
	{
		while (str[index] != '\0')
		{
			if (str[index] == ' ')
				break ;
			if (str[index] != 'n')
				return (FAIL);
			index++;
		}
		return (SUCCESS);
	}
	return (FAIL);
}

static void	print_home_path(t_data *data)
{
	char	*str;

	str = ft_strdup("$HOME");
	str = expand_variables_and_replace(data, str);
	printf("%s", str);
	free_str(str);
}

static void	echo_loop(t_data *data, char *str, char leading_space)
{
	if (leading_space)
		printf(" ");
	if (compare_str(str, "~") == 0)
		print_home_path(data);
	else
		printf("%s", str);
}

void	builtin_echo(t_data *data, char **args, int index)
{
	int	flag_n;

	flag_n = 0;
	while (args[index])
	{
		if (check_n(args[index]) == FAIL)
			break ;
		flag_n = 1;
		index++;
	}
	while (args[index] && ft_strlen(args[index]) < 1)
		index++;
	if (args[index])
		echo_loop(data, args[index++], 0);
	while (args[index])
	{
		if (ft_strlen(args[index]) >= 1)
			echo_loop(data, args[index], 1);
		index++;
	}
	if (!flag_n)
		printf("\n");
	g_ret_number = 0;
}
