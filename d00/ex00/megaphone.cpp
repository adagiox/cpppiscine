/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erintala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:24:57 by erintala          #+#    #+#             */
/*   Updated: 2018/01/08 14:56:10 by erintala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		std::string s(argv[i]);
		for (int j = 0; j < (int)s.length(); j++)
		{
			if (s[j] >= 'a' && s[j] <= 'z')
				s[j] = s[j] - 32;
		}
		std::cout << s;
		~s();std
	}
	std::cout << std::endl;
	return 0;
}
