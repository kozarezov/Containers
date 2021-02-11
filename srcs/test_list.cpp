/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:13 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/11 16:03:31 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Test_header.hpp"

void	print_header()
{
	std::cout << YELLOW;
	std::cout << "|-------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
	std::cout << "|        Тест        |           Оригинальный вывод           |           Ft_container вывод           |  Результат выполнения  |" << std::endl;
	std::cout << "|-------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
	std::cout << DEFAULT;
}

void	print_list(ft::list<int> &my, std::list<int> &orig, std::string test)
{
	std::stringstream	fout_my;
	std::stringstream	fout_orig;
	int					size_my = 0;
	int					size_orig = 0;
	std::string			result;

	for (std::list<int>::iterator it = orig.begin(); it != orig.end(); it++)
	{
		fout_orig << *it;
	}
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
	{
		fout_my << *it;
	}
	size_my = fout_my.str().length();
	size_orig = fout_orig.str().length();
	result = ((size_my == size_orig) ? GREEN "OK" : RED "FAIL");
	std::cout << YELLOW << "|" << DEFAULT;
	std::cout << "  " << BLUE << std::setw(18) << std::left << test << YELLOW << "|" << DEFAULT;
	std::cout << "  " << std::setw(38) << fout_orig.str() << YELLOW << "|" << DEFAULT;
	std::cout << "  " << std::setw(38) << fout_my.str() << YELLOW << "|" << DEFAULT;
	std::cout << "           " << std::setw(20) << result << YELLOW << "|" << std::endl;
	std::cout << "|-------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
	std::cout << DEFAULT;
}

void	test_list()
{
	print_header();
	{
		ft::list<int> a;
		std::list<int> b;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);
		print_list(a, b, "push_back");
	}
	{
		ft::list<int> a;
		std::list<int> b;

		a.push_front(1);
		a.push_front(2);
		a.push_front(3);
		b.push_front(1);
		b.push_front(2);
		b.push_front(3);
		print_list(a, b, "push_front");
	}
}