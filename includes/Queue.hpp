/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:03:06 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/13 15:14:05 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <iostream>
# include "List.hpp"

/* https://en.cppreference.com/w/cpp/container/queue */

namespace ft
{
	template< typename T, typename Container = ft::list<T> >
	class queue
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
	
		explicit queue (const container_type& ctnr = container_type())
		{
			this->head = ctnr;
		};
		
		queue( const queue& other )
		{
			*this = other;
		};

		queue& operator=( const queue& other )
		{
			if (this != &other)
				this->head = other.head;
			return (*this);
		};

		~queue()
		{
		};

	/* Element access */

		reference front()
		{
			return (this->head.front());
		};
		
		const_reference front() const 
		{
			return (this->head.front());
		};

		reference back()
		{
			return (this->head.back());
		};
		
		const_reference back() const 
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
			this->head.pop_front();
		};
	};
}

	/* Non-member functions */
	
template < class T, class Container >
bool operator==( const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs )
{
	return (lhs.getHead() == rhs.getHead());
};

template < class T, class Container >
bool operator!=( const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs )
{
	return (lhs.getHead() != rhs.getHead());
};

template < class T, class Container >
bool operator<( const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs )
{
	return (lhs.getHead() < rhs.getHead());
};

template < class T, class Container >
bool operator<=( const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs )
{
	return (lhs.getHead() <= rhs.getHead());
};

template < class T, class Container >
bool operator>( const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs )
{
	return (lhs.getHead() > rhs.getHead());
};

template < class T, class Container >
bool operator>=( const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs )
{
	return (lhs.getHead() >= rhs.getHead());
};

#endif