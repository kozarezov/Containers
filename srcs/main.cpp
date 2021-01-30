/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:05 by ceccentr          #+#    #+#             */
/*   Updated: 2021/01/30 11:31:11 by ceccentr         ###   ########.fr       */
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

        b.push_back(1);
        b.push_back(2);
        b.push_back(3);
        a.push_back(4);
        a.push_back(5);
        a.push_back(6);


        b.splice(b.begin(), a);
        for (ft::list<int>::iterator i = b.begin(); i != b.end(); i++)
        {
            std::cout << *i << std::endl;
        }
        for (ft::list<int>::iterator it = a.begin(); it != a.end(); it++)
        {
            std::cout << *it << std::endl;
        }
        std::cout << b.size() << " " << a.size() << std::endl;
    }

    std::cout << std::endl << std::endl;

    {
        std::list<int> a;
        std::list<int> b;

        b.push_back(1);
        b.push_back(2);
        b.push_back(3);
        a.push_back(4);
        a.push_back(5);
        a.push_back(6);


        b.splice(b.begin(), a);
        for (std::list<int>::iterator i = b.begin(); i != b.end(); i++)
        {
            std::cout << *i << std::endl;
        }
        for (std::list<int>::iterator it = a.begin(); it != a.end(); it++)
        {
            std::cout << *it << std::endl;
        }
        std::cout << b.size() << " " << a.size() << std::endl;
    }
    return (0);
}