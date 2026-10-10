/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:28:38 by gkhavari          #+#    #+#             */
/*   Updated: 2026/10/09 17:28:40 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void print_input(char *input)
{
	while (*input != '\0')
	{
		if (std::isalpha(*input))
			std::cout << (char)std::toupper(*input);
		else
			std::cout << *input;
		input++;
	}
}

int main(int ac, char **av)
{
	av++;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*av != NULL)
			{
				print_input(*av);
				av++;
			}
		std::cout << std::endl;
	}
	return (0);
}
