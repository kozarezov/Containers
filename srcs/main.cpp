/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:05 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/11 12:51:42 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/List.hpp"
#include <list>

int     main(void)
{
    {
        ft::list<int> a;
        ft::list<int> b;

        b.push_back(3);
        a.push_front(4);
        a.push_front(2);
        a.push_front(4);
        a.push_front(6);

        a.sort();
        ft::swap(a, b);
        std::cout << (a < b) << std::endl;
        for (ft::list<int>::iterator it = a.begin(); it != a.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::list<int> a;
        std::list<int> b;

        b.push_back(3);
        a.push_front(4);
        a.push_front(2);
        a.push_front(4);
        a.push_front(6);

        a.sort();
        std::swap(a, b);
        std::cout << (a < b) << std::endl;
        for (std::list<int>::iterator it = a.begin(); it != a.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    return (0);
}