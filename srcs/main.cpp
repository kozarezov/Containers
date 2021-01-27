/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:05 by ceccentr          #+#    #+#             */
/*   Updated: 2021/01/27 17:38:42 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/List.hpp"
#include <list>

int     main(void)
{
    ft::list<int> a;
    ft::list<int> b;

    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);


    b.merge(a);
    for (ft::list<int>::iterator i = b.begin(); i != b.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    return (0);
}