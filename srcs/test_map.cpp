/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:16 by ceccentr          #+#    #+#             */
/*   Updated: 2021/04/13 15:36:23 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Test_header.hpp"

void	print_map(ft::map<int, std::string> &my, std::map<int, std::string> &orig, std::string test, int flag)
{
	std::stringstream	fout_my;
	std::stringstream	fout_orig;
	int					size_my = 0;
	int					size_orig = 0;
	std::string			result;

	for (std::map<int, std::string>::iterator it = orig.begin(); it != orig.end(); it++)
	{
		fout_orig << it->first << "-" << it->second << "; ";
	}
	fout_orig << " [" << orig.size() << "]";
	for (ft::map<int, std::string>::iterator it = my.begin(); it != my.end(); it++)
	{
		fout_my << it->first << "-" << it->second << "; ";;
	}
	fout_my << " [" << my.size() << "]";
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

void	print_element(ft::map<int, std::string>::iterator my, std::map<int, std::string>::iterator orig, std::string test, int flag)
{
	std::stringstream	fout_my;
	std::stringstream	fout_orig;
	int					size_my = 0;
	int					size_orig = 0;
	std::string			result;

	fout_orig << orig->first << "-" << orig->second;
	fout_my << my->first << "-" << my->second;

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

void	test_map()
{
	print_header("Constructors");

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;

		print_map(a, b, "empty_map", 0);
	}

	{
		std::map<int, std::string> c;

		c[1] = "one";
		c[2] = "two";

		ft::map<int, std::string> a(c.begin(), c.end());
		std::map<int, std::string> b(c.begin(), c.end());

		print_map(a, b, "array_elements", 0);
	}

	{
		std::map<int, std::string> c;
		ft::map<int, std::string> d;

		c[1] = "one";
		c[2] = "two";
		d[1] = "one";
		d[2] = "two";

		ft::map<int, std::string> a(d);
		std::map<int, std::string> b(c);

		print_map(a, b, "copy_list", 0);
	}

	{
		std::map<int, std::string> c;
		ft::map<int, std::string> d;

		c[1] = "one";
		c[2] = "two";
		d[1] = "one";
		d[2] = "two";

		ft::map<int, std::string> a = d;
		std::map<int, std::string> b = c;

		print_map(a, b, "operator=", 0);
	}

	print_header("Element access");

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;

		a[1] = "one";
		a[2] = "two";
		b[1] = "one";
		b[2] = "two";

		print_map(a, b, "operator[]", 0);
	}

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;

		a[1] = "one";
		a[2] = "two";
		b[1] = "one";
		b[2] = "two";

		print_element(a.begin(), b.begin(), "begin", 0);
	}

	print_header("Capacity");

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;

		a[1] = "one";
		a[2] = "two";
		b[1] = "one";
		b[2] = "two";

		print_element(a.size(), b.size(), "size", 0);
		print_element(a.max_size(), b.max_size(), "max_size", 0);
		print_element(a.empty(), b.empty(), "empty", 0);
	}

	print_header("Modifiers");

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;

		a.insert(std::pair<int, std::string>(3, "three"));
		b.insert(std::pair<int, std::string>(3, "three"));

		print_map(a, b, "insert_element", 0);

		a.insert(a.begin(), std::pair<int, std::string>(4, "four"));
		b.insert(b.begin(), std::pair<int, std::string>(4, "four"));

		print_map(a, b, "insert_hint", 0);
	}

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;
		ft::map<int, std::string> c;
		std::map<int, std::string> d;

		c[1] = "one";
		c[2] = "two";
		d[1] = "one";
		d[2] = "two";

		a.insert(c.begin(), c.end());
		b.insert(d.begin(), d.end());

		print_map(a, b, "insert_array", 0);

		a.erase(a.begin());
		b.erase(b.begin());
		print_map(a, b, "erase", 0);
	}

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;

		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		b[1] = "one";
		b[2] = "two";
		b[3] = "three";
		b[4] = "four";


		ft::map<int, std::string>::iterator beg_a = a.begin();
		ft::map<int, std::string>::iterator end_a = a.end();
		std::map<int, std::string>::iterator beg_b = b.begin();
		std::map<int, std::string>::iterator end_b = b.end();
		beg_a++;
		beg_b++;
		end_a--;
		end_b--;
		
		a.erase(beg_a, end_a);
		b.erase(beg_b, end_b);
		print_map(a, b, "erase_array", 0);

		a.erase(1);
		b.erase(1);
		print_map(a, b, "erase_key", 0);
	}

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;
		ft::map<int, std::string> c;
		std::map<int, std::string> d;

		a[1] = "one";
		a[2] = "two";
		a[3] = "three";

		b[1] = "one";
		b[2] = "two";
		b[3] = "three";

		c[3] = "one";
		c[2] = "two";
		c[1] = "three";

		d[3] = "one";
		d[2] = "two";
		d[1] = "three";

		a.swap(c);
		b.swap(d);
		print_map(a, b, "swap", 0);
	}

	print_header("lookup");

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;

		a[1] = "one";
		a[2] = "two";
		a[3] = "three";

		b[1] = "one";
		b[2] = "two";
		b[3] = "three";

		print_element(a.count(1), b.count(1), "count", 0);
		print_element(a.find(1), b.find(1), "find", 0);
		print_element(a.lower_bound(1), b.lower_bound(1), "lower_bound", 0);
		print_element(a.upper_bound(1), b.upper_bound(1), "upper_bound", 0);
		print_element(a.equal_range(1).first, b.equal_range(1).first, "equal_range", 0);
		print_element(a.key_comp()(1, 2), b.key_comp()(1, 2), "key_comp", 0);
		print_element(a.value_comp()(std::pair< int, std::string>(1, "one"), std::pair< int, std::string>(2, "two")), b.value_comp()(std::pair< int, std::string>(1, "one"), std::pair< int, std::string>(2, "two")), "value_comp", 0);
	}

	print_header("Non-member functions");

	{
		ft::map<int, std::string> a;
		std::map<int, std::string> b;
		ft::map<int, std::string> c;
		std::map<int, std::string> d;

		a[1] = "one";
		a[2] = "two";
		a[3] = "three";

		b[1] = "one";
		b[2] = "two";
		b[3] = "three";

		c[3] = "one";
		c[2] = "two";
		c[1] = "three";

		d[3] = "one";
		d[2] = "two";
		d[1] = "three";

		ft::swap(a, c);
		std::swap(b, d);
		print_map(a, b, "swap", 0);

		print_element(a < c, b < d, "operator <", 0);
		print_element(a <= c, b <= d, "operator <=", 0);
		print_element(a > c, b > d, "operator >", 0);
		print_element(a >= c, b >= d, "operator >=", 0);
		print_element(a == c, b == d, "operator ==", 0);
		print_element(a != c, b != d, "operator !=", 0);
	}
}