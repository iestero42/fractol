/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:14:39 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/08 12:53:51 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long int	binomialcoeff(int n, int k)
{
	int						i;
	unsigned long long int	result;

	if (k == 0 || k == n)
		return (1);
	result = 1;
	i = 0;
	while (i <= k)
	{
		result *= (n - i + 1);
		result /= i;
	}
	return (result);
}
