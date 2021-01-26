/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:05 by ceccentr          #+#    #+#             */
/*   Updated: 2021/01/25 23:12:22 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/List.hpp"
#include <list>

int     main(void)
{
    size_t len;
    size_t len1;

    ft::list<int> a;
    std::list<int> b;

    len = a.max_size();
    std::cout << len << std::endl;

    len1 = b.max_size();
    std::cout << len1 << std::endl;

    return (0);
}