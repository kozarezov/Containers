/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:05 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/13 14:43:45 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Test_header.hpp"

int		print_header()
{
	static const std::string arr[] = { "Exit", "List", "Stack", "Map", "Queue", "Vector" };
	int i;

	std::cout << YELLOW;
	std::cout << std::endl;
	std::cout << "|--------------------|" << std::endl;
	std::cout << "|  Запустить тест:   |" << std::endl;
	std::cout << "|  [0]. Exit         |" << std::endl;
	std::cout << "|  [1]. List         |" << std::endl;
	std::cout << "|  [2]. Stack        |" << std::endl;
	std::cout << "|  [3]. Map          |" << std::endl;
	std::cout << "|  [4]. Queue        |" << std::endl;
	std::cout << "|  [5]. Vector       |" << std::endl;
	std::cout << "|--------------------|" << std::endl;
	std::cout << std::endl;
	std::cout << DEFAULT;
	std::cin >> i;
	if (i < 0 || i > 5)
		return (-1);
	std::cout << RED;
	std::cout << "                                                         --- " << arr[i] << " ---" << std::endl;
	if (i > 0)
	{
		std::cout << YELLOW;
		std::cout << "|-------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
		std::cout << "|        Тест        |           Оригинальный вывод           |           Ft_containers вывод          |  Результат выполнения  |" << std::endl;
		std::cout << "|-------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
	}
	std::cout << DEFAULT;
	return (i);
};

void	print_header(std::string str)
{
	std::cout << YELLOW << "|" << DEFAULT << std::left;
	std::cout << BLUE << "                                                        #" << std::setw(70) << str << YELLOW << "|" << std::endl;
	std::cout << "|-------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
	std::cout << DEFAULT;
};

int     main(void)
{
	int a;

	while (1)
	{
		a = print_header();
		if (a == 0)
			break;
		if (a == 1)
			test_list();
		if (a == 2)
			test_stack();
	}
	return (0);
}