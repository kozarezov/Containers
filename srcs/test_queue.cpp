/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:18 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/13 15:29:54 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Test_header.hpp"

void	print_queue(ft::queue<int> my, std::queue<int> orig, std::string test, int flag)
{
	std::stringstream	fout_my;
	std::stringstream	fout_orig;
	int					size_my = 0;
	int					size_orig = 0;
	std::string			result;

	fout_orig << "[" << orig.size() << "] ";
	while (orig.empty() == 0)
	{
		fout_orig << orig.front();
		orig.pop();
	}
	fout_my << "[" << my.size() << "] ";
	while (my.empty() == 0)
	{
		fout_my << my.front();
		my.pop();
	}
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

void	test_queue()
{
	print_header("Constructors");

	{
		ft::queue<int> a;
		std::queue<int> b;

		print_queue(a, b, "empty_queue", 0);
	}
	{
		ft::queue<int> a;
		std::queue<int> b;

		a.push(1);
		a.push(2);
		a.push(3);
		b.push(1);
		b.push(2);
		b.push(3);

		ft::queue<int>c(a);
		std::queue<int> d(b);

		print_queue(c, d, "copy_queue", 0);
	}
	{
		ft::queue<int> a;
		std::queue<int> b;

		a.push(1);
		a.push(2);
		a.push(3);
		b.push(1);
		b.push(2);
		b.push(3);

		ft::queue<int>c = a;
		std::queue<int> d = b;

		print_queue(c, d, "operator=", 0);
	}

	print_header("Modifiers");

	{
		ft::queue<int> a;
		std::queue<int> b;

		a.push(1);
		a.push(2);
		a.push(3);
		b.push(1);
		b.push(2);
		b.push(3);

		print_queue(a, b, "push", 0);

		a.pop();
		b.pop();

		print_queue(a, b, "pop", 0);
	}

	print_header("Capacity");

	{
		ft::queue<int> a;
		std::queue<int> b;

		a.push(1);
		a.push(2);
		a.push(3);
		b.push(1);
		b.push(2);
		b.push(3);

		print_element(a.size(), b.size(), "size", 0);
		print_element(a.empty(), b.empty(), "empty", 0);
	}

	print_header("Element access");

	{
		ft::queue<int> a;
		std::queue<int> b;

		a.push(1);
		a.push(2);
		a.push(3);
		b.push(1);
		b.push(2);
		b.push(3);

		print_element(a.front(), b.front(), "front", 0);
	}
	{
		ft::queue<int> a;
		std::queue<int> b;

		a.push(1);
		a.push(2);
		a.push(3);
		b.push(1);
		b.push(2);
		b.push(3);

		print_element(a.back(), b.back(), "back", 0);
	}

	print_header("Non-member functions");

	{
		ft::queue<int> a;
		std::queue<int> b;
		ft::queue<int> c;
		std::queue<int> d;

		a.push(1);
		a.push(2);
		a.push(3);
		b.push(1);
		b.push(2);
		b.push(3);
		c.push(3);
		c.push(2);
		c.push(1);
		d.push(3);
		d.push(2);
		d.push(1);

		print_element(a == c, b == d, "operator ==", 0);
		print_element(a != c, b != d, "operator !=", 0);
		print_element(a > c, b > d, "operator >", 0);
		print_element(a >= c, b >= d, "operator >=", 0);
		print_element(a < c, b < d, "operator <", 0);
		print_element(a <= c, b <= d, "operator <=", 0);
	}
}