/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:22 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/19 11:12:48 by ceccentr         ###   ########.fr       */
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
	/* fout_orig << " [" << orig.capacity() << "]"; */
	for (ft::vector<int>::iterator it1 = my.begin(); it1 != my.end(); it1++)
	{
		fout_my << *it1;
	}
	fout_my << " [" << my.size() << "]";
	/* fout_my << " [" << my.capacity() << "]"; */
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

void	print_element(ft::vector<int>::iterator my, std::vector<int>::iterator orig, std::string test, int flag)
{
	std::stringstream	fout_my;
	std::stringstream	fout_orig;
	int					size_my = 0;
	int					size_orig = 0;
	std::string			result;

	fout_orig << *orig;
	fout_my << *my;

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
	print_header("Constructors");
	
	{
		ft::vector<int> a;
		std::vector<int> b;

		print_vector(a, b, "empty_vector", 0);
	}
	{
		ft::vector<int> a(5);
		std::vector<int> b(5);

		print_vector(a, b, "empty_elements", 0);
	}
	{
		ft::vector<int> a(5, 21);
		std::vector<int> b(5, 21);

		print_vector(a, b, "value_elements", 0);
	}
	{
		std::vector<int> c;

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);

		ft::vector<int> a(c.begin(), c.end());
		std::vector<int> b(c.begin(), c.end());

		print_vector(a, b, "array_elements", 0);
	}
	{
		std::vector<int> c;
		ft::vector<int> d;

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		d.push_back(1);
		d.push_back(2);
		d.push_back(3);

		ft::vector<int> a(d);
		std::vector<int> b(c);

		print_vector(a, b, "copy_vector", 0);
	}
	{
		std::vector<int> c;
		ft::vector<int> d;

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		d.push_back(1);
		d.push_back(2);
		d.push_back(3);

		ft::vector<int> a = d;
		std::vector<int> b = c;

		print_vector(a, b, "operator=", 0);
	}

	print_header("Add Elements");

	{
		ft::vector<int> a;
		std::vector<int> b;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);
		print_vector(a, b, "push_back", 0);
	}
	{
		ft::vector<int> a;
		std::vector<int> b;

		a.assign(5, 3);
		b.assign(5, 3);
		print_vector(a, b, "assign", 0);
	}
	{
		std::vector<int> c;

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		
		ft::vector<int> a;
		std::vector<int> b;

		a.assign(c.begin(), c.end());
		b.assign(c.begin(), c.end());
		print_vector(a, b, "array_assign", 0);
	}

	print_header("Element access");

	{
		ft::vector<int> a;
		std::vector<int> b;

		a.push_back(21);
		a.push_back(42);
		b.push_back(21);
		b.push_back(42);

		print_element(a.front(), b.front(), "front", 0);
		print_element(a.back(), b.back(), "back", 0);
		print_element(a.at(1), b.at(1), "at", 0);
		print_element(a[0], b[0], "operator[]", 0);
		print_element(a.begin(), b.begin(), "begin", 0);
		print_element(a.end(), b.end(), "end", 1);
	}

	print_header("Capacity");

	{
		ft::vector<int> a;
		std::vector<int> b;

		a.push_back(1);
		a.push_back(2);
		b.push_back(1);
		b.push_back(2);
		
		print_element(a.size(), b.size(), "size", 0);
		print_element(a.capacity(), b.capacity(), "capacity", 0);
		print_element(a.max_size(), b.max_size(), "max_size", 0);
		print_element(a.empty(), b.empty(), "empty", 0);
	}

	print_header("Modifiers");

	{
		ft::vector<int> a;
		std::vector<int> b;
		std::vector<int> c;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);
		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		
		a.insert(a.end(), 4);
		b.insert(b.end(), 4);
		print_vector(a, b, "insert_element", 0);

		a.insert(a.end(), 2, 5);
		b.insert(b.end(), 2, 5);
		print_vector(a, b, "insert_elements", 0);

		a.insert(a.end(), c.begin(), c.end());
		b.insert(b.end(), c.begin(), c.end());
		print_vector(a, b, "insert_array", 0);

		a.erase(a.begin());
		b.erase(b.begin());
		print_vector(a, b, "erase", 0);

		ft::vector<int>::iterator beg_a = a.begin();
		ft::vector<int>::iterator end_a = a.end();
		std::vector<int>::iterator beg_b = b.begin();
		std::vector<int>::iterator end_b = b.end();
		beg_a++;
		beg_a++;
		beg_b++;
		beg_b++;
		end_a--;
		end_a--;
		end_b--;
		end_b--;
		
		a.erase(beg_a, end_a);
		b.erase(beg_b, end_b);
		print_vector(a, b, "erase_array", 0);

		a.pop_back();
		b.pop_back();
		print_vector(a, b, "pop_back", 0);

		a.resize(5);
		b.resize(5);
		print_vector(a, b, "resize", 0);

		a.clear();
		b.clear();
		print_vector(a, b, "clear", 0);
	}

	print_header("Non-member functions");

	{
		ft::vector<int> a;
		std::vector<int> b;
		ft::vector<int> c;
		std::vector<int> d;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);

		c.push_back(3);
		c.push_back(2);
		c.push_back(1);
		d.push_back(3);
		d.push_back(2);
		d.push_back(1);

		ft::swap(a, c);
		std::swap(b, d);
		print_vector(a, b, "swap", 0);

		print_element(a < c, b < d, "operator <", 0);
		print_element(a <= c, b <= d, "operator <=", 0);
		print_element(a > c, b > d, "operator >", 0);
		print_element(a >= c, b >= d, "operator >=", 0);
		print_element(a == c, b == d, "operator ==", 0);
		print_element(a != c, b != d, "operator !=", 0);
	
	}
}