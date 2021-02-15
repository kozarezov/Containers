/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:32:00 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/15 13:50:17 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "ITVector.hpp"

/* https://en.cppreference.com/w/cpp/container/vector */

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
	/* Member types */
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename ft::ITVector<T>					iterator;
		typedef typename ft::ConstITVector<T>				const_iterator;
		typedef typename ft::ReverseITVector<T>				reverse_iterator;
		typedef typename ft::ConstReverseITVector<T>		const_reverse_iterator;

	private:
		size_type		_size;
		size_type		_capacity;
		value_type		*_ptr;
		allocator_type	_alloc;

	public:
	/* My functions */

	/* ... */

	/* Member functions */
	
	};
}


#endif