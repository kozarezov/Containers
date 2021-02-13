/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:00:01 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/13 13:42:08 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include "List.hpp"

/* https://en.cppreference.com/w/cpp/container/stack */

namespace ft
{
	template< typename T, typename Container = ft::list<T> >
	class stack
	{
	/* Member types */
	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef	typename Container::size_type		size_type;
		typedef	typename Container::reference		reference;
		typedef	typename Container::const_reference const_reference;
		
	private:
		container_type head;

	public:
	/* My functions */
		container_type const &getHead() const
		{
			return (this->head);
		};

	/* Member functions */
	
		explicit stack (const container_type& ctnr = container_type())
		{
			this->head = ctnr;
		};
		
		stack( const stack& other )
		{
			*this = other;
		};

		stack& operator=( const stack& other )
		{
			if (this != &other)
				this->head = other.head;
			return (*this);
		};

		~stack()
		{
		};

	/* Element access */

		reference top()
		{
			return (this->head.back());
		};
		
		const_reference top() const 
		{
			return (this->head.back());
		};

	/* Capacity */

		bool empty() const
		{
			return (this->head.empty());
		};

		size_type size() const
		{
			return (this->head.size());
		};

	/* Modifiers */

		void push( const value_type& value )
		{
			this->head.push_back(value);
		};

		void pop()
		{
			this->head.pop_back();
		};
	};
}

	/* Non-member functions */
	
template < class T, class Container >
bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return (lhs.getHead() == rhs.getHead());
};

template < class T, class Container >
bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return (lhs.getHead() != rhs.getHead());
};

template < class T, class Container >
bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return (lhs.getHead() < rhs.getHead());
};

template < class T, class Container >
bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return (lhs.getHead() <= rhs.getHead());
};

template < class T, class Container >
bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return (lhs.getHead() > rhs.getHead());
};

template < class T, class Container >
bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return (lhs.getHead() >= rhs.getHead());
};

#endif