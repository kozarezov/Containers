/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:13 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/13 12:09:48 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Test_header.hpp"

bool	cmp(int nbr)
{
	return (nbr == 1);
}

bool	p(int nbr1, int nbr2)
{
	return (nbr1 == nbr2);
}

bool	comp(int nbr1, int nbr2)
{
	return (nbr1 > nbr2);
}

void	print_list(ft::list<int> &my, std::list<int> &orig, std::string test, int flag)
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
	fout_orig << " [" << orig.size() << "]";
	for (ft::list<int>::iterator it = my.begin(); it != my.end(); it++)
	{
		fout_my << *it;
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

void	print_element(ft::list<int>::iterator my, std::list<int>::iterator orig, std::string test, int flag)
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

void	test_list()
{
	print_header("Constructors");
	
	{
		ft::list<int> a;
		std::list<int> b;

		print_list(a, b, "empty_list", 0);
	}
	{
		ft::list<int> a(5);
		std::list<int> b(5);

		print_list(a, b, "empty_elements", 0);
	}
	{
		ft::list<int> a(5, 21);
		std::list<int> b(5, 21);

		print_list(a, b, "value_elements", 0);
	}
	{
		std::list<int> c;

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);

		ft::list<int> a(c.begin(), c.end());
		std::list<int> b(c.begin(), c.end());

		print_list(a, b, "array_elements", 0);
	}
	{
		std::list<int> c;
		ft::list<int> d;

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		d.push_back(1);
		d.push_back(2);
		d.push_back(3);

		ft::list<int> a(d);
		std::list<int> b(c);

		print_list(a, b, "copy_list", 0);
	}
	{
		std::list<int> c;
		ft::list<int> d;

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		d.push_back(1);
		d.push_back(2);
		d.push_back(3);

		ft::list<int> a = d;
		std::list<int> b = c;

		print_list(a, b, "operator=", 0);
	}

	print_header("Add Elements");

	{
		ft::list<int> a;
		std::list<int> b;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);
		print_list(a, b, "push_back", 0);
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
		print_list(a, b, "push_front", 0);
	}
	{
		ft::list<int> a;
		std::list<int> b;

		a.assign(5, 3);
		b.assign(5, 3);
		print_list(a, b, "assign", 0);
	}
	{
		std::list<int> c;

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		
		ft::list<int> a;
		std::list<int> b;

		a.assign(c.begin(), c.end());
		b.assign(c.begin(), c.end());
		print_list(a, b, "array_assign", 0);
	}

	print_header("Element access");

	{
		ft::list<int> a;
		std::list<int> b;

		a.push_back(21);
		a.push_back(42);
		b.push_back(21);
		b.push_back(42);

		print_element(a.front(), b.front(), "front", 0);
		print_element(a.back(), b.back(), "back", 0);
		print_element(a.begin(), b.begin(), "begin", 0);
		print_element(a.end(), b.end(), "end", 1);
	}

	print_header("Capacity");

	{
		ft::list<int> a;
		std::list<int> b;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);
		
		print_element(a.size(), b.size(), "size", 0);
		print_element(a.max_size(), b.max_size(), "max_size", 0);
		print_element(a.empty(), b.empty(), "empty", 0);
	}

	print_header("Modifiers");

	{
		ft::list<int> a;
		std::list<int> b;
		std::list<int> c;

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
		print_list(a, b, "insert_element", 0);

		a.insert(a.end(), 2, 5);
		b.insert(b.end(), 2, 5);
		print_list(a, b, "insert_elements", 0);

		a.insert(a.end(), c.begin(), c.end());
		b.insert(b.end(), c.begin(), c.end());
		print_list(a, b, "insert_array", 0);

		a.erase(a.begin());
		b.erase(b.begin());
		print_list(a, b, "erase", 0);

		ft::list<int>::iterator beg_a = a.begin();
		ft::list<int>::iterator end_a = a.end();
		std::list<int>::iterator beg_b = b.begin();
		std::list<int>::iterator end_b = b.end();
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
		print_list(a, b, "erase_array", 0);

		a.pop_back();
		b.pop_back();
		print_list(a, b, "pop_back", 0);

		a.pop_front();
		b.pop_front();
		print_list(a, b, "pop_front", 0);

		a.resize(5);
		b.resize(5);
		print_list(a, b, "resize", 0);

		a.clear();
		b.clear();
		print_list(a, b, "clear", 0);
	}
	{
		ft::list<int> a;
		std::list<int> b;
		ft::list<int> c;
		std::list<int> d;

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
		
		a.swap(c);
		b.swap(d);
		print_list(a, b, "swap", 0);
	}

	print_header("Operations");

	{
		ft::list<int> a;
		std::list<int> b;
		ft::list<int> c;
		std::list<int> d;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		d.push_back(1);
		d.push_back(2);
		d.push_back(3);

		a.merge(c);
		b.merge(d);
		print_list(a, b, "merge", 0);
	}
	{
		ft::list<int> a;
		std::list<int> b;
		ft::list<int> c;
		std::list<int> d;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		d.push_back(1);
		d.push_back(2);
		d.push_back(3);

		a.splice(a.end(), c, c.begin());
		b.splice(b.end(), d, d.begin());
		print_list(a, b, "splice_element", 0);
	}
	{
		ft::list<int> a;
		std::list<int> b;
		ft::list<int> c;
		std::list<int> d;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		d.push_back(1);
		d.push_back(2);
		d.push_back(3);

		a.splice(a.end(), c);
		b.splice(b.end(), d);
		print_list(a, b, "splice_elements", 0);
	}
	{
		ft::list<int> a;
		std::list<int> b;
		ft::list<int> c;
		std::list<int> d;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);

		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		d.push_back(1);
		d.push_back(2);
		d.push_back(3);

		a.splice(a.end(), c, ++c.begin(), c.end());
		b.splice(b.end(), d, ++d.begin(), d.end());
		print_list(a, b, "splice_array", 0);

		a.remove(2);
		b.remove(2);
		print_list(a, b, "remove", 0);

		a.remove_if(cmp);
		b.remove_if(cmp);
		print_list(a, b, "remove_if(cmp)", 0);

		a.unique();
		b.unique();
		print_list(a, b, "unique", 0);

		a.push_back(3);
		b.push_back(3);
		a.unique(p);
		b.unique(p);
		print_list(a, b, "unique(p)", 0);

		a.push_back(5);
		a.push_back(9);
		a.push_back(2);
		b.push_back(5);
		b.push_back(9);
		b.push_back(2);
		a.sort();
		b.sort();
		print_list(a, b, "sort", 0);

		a.sort(comp);
		b.sort(comp);
		print_list(a, b, "sort(comp)", 0);
	}

	print_header("Non-member functions");

	{
		ft::list<int> a;
		std::list<int> b;
		ft::list<int> c;
		std::list<int> d;

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
		print_list(a, b, "swap", 0);

		print_element(a < c, b < d, "operator <", 0);
		print_element(a <= c, b <= d, "operator <=", 0);
		print_element(a > c, b > d, "operator >", 0);
		print_element(a >= c, b >= d, "operator >=", 0);
		print_element(a == c, b == d, "operator ==", 0);
		print_element(a != c, b != d, "operator !=", 0);
	
	}
}