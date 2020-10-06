/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:34:36 by rfrank            #+#    #+#             */
/*   Updated: 2020/10/05 20:34:37 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		convert(char *str, int *it, long int res, int is_positive)
{
	while (str[it[0]])
	{
		if (it[1] == 0 && (str[it[0]] == 32 || str[it[0]] == '-'
			|| str[it[0]] == '+' || (str[it[0]] > 8 && str[it[0]] < 14)))
		{
			if (str[it[0]] == '-')
			{
				is_positive = -1;
				it[1]++;
			}
			else if (str[it[0]] == '+')
				it[1]++;
		}
		else if (str[it[0]] < '0' || str[it[0]] > '9')
			return (res * is_positive);
		else if (str[it[0]] >= '0' && str[it[0]] <= '9')
		{
			res = res * 10 + (str[it[0]] - '0');
			it[1]++;
		}
		it[0]++;
	}
	return (res * is_positive);
}

int		ft_atoi(char *str)
{
	int			it[2];
	long int	res;
	int			is_positive;

	it[0] = 0;
	it[1] = 0;
	res = 0;
	is_positive = 1;
	return (convert(str, it, res, is_positive));
}
