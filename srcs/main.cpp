/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:05 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/10 14:26:00 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/List.hpp"
#include <list>

int     main(void)
{
    {
        ft::list<int> a;

        a.push_front(4);
        a.push_front(5);
        a.push_front(6);

        a.reverse();
        for (ft::list<int>::iterator it = a.begin(); it != a.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::list<int> a;

        a.push_front(4);
        a.push_front(5);
        a.push_front(6);

        a.reverse();
        for (std::list<int>::iterator it = a.begin(); it != a.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    return (0);
}