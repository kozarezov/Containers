/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_header.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:58:15 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/12 17:29:41 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEADER_HPP
# define TEST_HEADER_HPP

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;36m"
# define DEFAULT "\033[0m"
# define LIST "List"
# define STACK "Stack"
# define MAP "Map"
# define QUEUE "Queue"
# define VECTOR "Vector"

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <string>
# include <iterator>
# include <iomanip>
# include "List.hpp"
# include <list>
# include <vector>

int		main();
void	test_list();
int		print_header();
void	print_header(std::string str);

#endif