/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:05 by ceccentr          #+#    #+#             */
/*   Updated: 2021/01/27 13:16:53 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/List.hpp"
#include <list>

int     main(void)
{
    std::list<int> a;
    std::list<int> b;

    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);


    b.merge(b);
    for (std::list<int>::iterator i = b.begin(); i != b.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    return (0);
}