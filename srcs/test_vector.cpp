/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:22 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/17 15:17:08 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Test_header.hpp"

void	print_vector(ft::vector<int> &my, std::vector<int> &orig, std::string test, int flag)
{
	std::stringstream	fout_my;
	std::stringstream	fout_orig;
	int					size_my = 0;
	int					size_orig = 0;
	std::string			result;

	for (std::vector<int>::iterator it = orig.begin(); it != orig.end(); it++)
	{
		fout_orig << *it;
	}
	fout_orig << " [" << orig.size() << "]";
	fout_orig << " [" << orig.capacity() << "]";
	for (ft::vector<int>::iterator it1 = my.begin(); it1 != my.end(); it1++)
	{
		fout_my << *it1;
	}
	fout_my << " [" << my.size() << "]";
	fout_my << " [" << my.capacity() << "]";
	size_my = fout_my.str().length();
	size_orig = fout_orig.str().length();
	if (flag == 1)
		result = YELLOW "UNDEFINED";
	else
		result = ((size_my == size_orig && fout_my.str() == fout_orig.str()) ? GREEN "OK" : RED "FAIL");
	std::cout << YELLOW << "|" << DEFAULT;
	std::cout << "  " << BLUE << std::setw(18) << std::left << test << YELLOW << "|" << DEFAULT;
	std::cout << "  " << std::setw(38) << fout_orig.str() << YELLOW << "|" << DEFAULT;
	std::cout << "  " << std::setw(38) << fout_my.str() << YELLOW << "|" << DEFAULT;
	std::cout << "           " << std::setw(20) << result << YELLOW << "|" << std::endl;
	std::cout << "|-------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
	std::cout << DEFAULT;
}

void	test_vector()
{
	{
		ft::vector<int> a;
		std::vector<int> b;

		a.push_back(1);
		b.push_back(1);

		a.insert(a.begin(), (size_t)(4), 3);
		b.insert(b.begin(), 4, 3);
		print_vector(a, b, "empty_list", 0);
	}
}