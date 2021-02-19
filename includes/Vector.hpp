/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:32:00 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/19 10:58:20 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <limits>
# include "ITVector.hpp"

/* https://en.cppreference.com/w/cpp/container/vector */
/* Capacity - undefind в зависимости от версии компилятора
https://ravesli.com/urok-106-emkost-vektora-std-vector-v-kachestve-steka/ */

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
	/* Member types */
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef typename Allocator::reference				reference;
		typedef typename Allocator::const_reference			const_reference;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;
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

	/* Member functions */
		vector() : _ptr(nullptr)
		{
			this->_size = 0;
			this->_capacity = 0;
		};

		explicit vector ( const Allocator& alloc ) : _ptr(nullptr)
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_alloc = alloc;
		};

		explicit vector ( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		{
			this->_alloc = alloc;
			if (count > 0)
			{
				this->_size = count;
				this->_capacity = count;
				this->_ptr = this->_alloc.allocate(count);
				for (size_type i = 0; i < count; i++)
					this->_ptr[i] = value;
			}
			else
			{
				this->_size = 0;
				this->_capacity = 0;
				this->_alloc = alloc;
			}
		};

		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() )
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_alloc = alloc;
			assign(first, last);
		};

		vector( const vector& other )
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_alloc = other._alloc;
			*this = other;
		}

		~vector()
		{
			if (this->_capacity > 0)
				this->_alloc.deallocate(this->_ptr, this->_capacity);
		};


		vector &operator=( const vector& other )
		{
			this->clear();
			if (other.empty() || (this == &other))
				return (*this);
			assign(other.begin(), other.end());
			return (*this);
		};

		void assign( size_type count, const T& value )
		{
			this->clear();
			for (size_type i = 0; i < count; i++)
				this->push_back(value);
		};

		template< class InputIt >
		void assign( InputIt first, typename std::enable_if < std::is_class <InputIt>::value, InputIt>::type last )
		{
			this->clear();
			while (first != last)
			{
				this->push_back(*first);
				++first;
			}
		};

	/* Element access */

		reference at( size_type pos )
		{
			if (pos >= this->_size)
				throw std::out_of_range("out of range");
			return (this->_ptr[pos]);
		};

		const_reference at( size_type pos ) const
		{
			if (pos >= this->_size)
				throw std::out_of_range("out of range");
			return (this->_ptr[pos]);
		};

		reference operator[]( size_type pos )
		{
			return (this->_ptr[pos]);
		};

		const_reference operator[]( size_type pos ) const
		{
			return (this->_ptr[pos]);
		};

		reference front()
		{
			return (this->_ptr[0]);
		};

		const_reference front() const
		{
			return (this->_ptr[0]);
		};

		reference back()
		{
			return (this->_ptr[this->_size - 1]);
		};

		const_reference back() const
		{
			return (this->_ptr[this->_size - 1]);
		};

	/* Iterators */

		iterator begin()
		{
			return (iterator(this->_ptr));
		};

		const_iterator begin() const
		{
			return (const_iterator(this->_ptr));
		};

		iterator end()
		{
			return (iterator(this->_ptr + this->_size));
		};
		
		const_iterator end() const 
		{
			return (const_iterator(this->_ptr + this->_size));
		};
		reverse_iterator rbegin() 
		{
			return (reverse_iterator(this->_ptr + this->_size - 1));
		};
		
		const_reverse_iterator rbegin() const 
		{
			return (const_reverse_iterator(this->_ptr + this->_size - 1));
		};
		
		reverse_iterator rend()
		{
			return (reverse_iterator(this->_ptr - 1));
		};

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->_ptr - 1));
		};

	/* Capacity */

		bool empty() const
		{
			return (this->_size == 0);
		};

		size_type size() const
		{
			return (this->_size);
		};

		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		};

		void reserve( size_type new_cap )
		{
			value_type *temp;

			if (this->_capacity < new_cap)
			{
				temp = this->_alloc.allocate(new_cap);
				for (size_type i = 0; i < this->_size; i++)
					temp[i] = this->_ptr[i];
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = temp;
				this->_capacity = new_cap;
			}
		};

		size_type capacity() const
		{
			return (this->_capacity);
		};

	/* Modifiers */

		void clear()
		{
			if (this->_size != 0)
			{
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = nullptr;
				this->_size = 0;
				this->_capacity = 0;
			}
		};

		iterator insert( iterator pos, const T& value )
		{
			size_type position = pos - this->begin();
			
			insert(pos, 1, value);
			return (iterator(this->_ptr + position));
		};

		void insert( iterator pos, size_type count, const T& value )
		{
			vector<T> temp(pos, this->end());
			iterator begin = temp.begin();
			iterator end = temp.end();
			size_type len = temp.end() - temp.begin();
			
			for (size_type i = 0; i < len; i++)
				this->pop_back();
			
			for (size_type i = 0; i < count; i++)
				this->push_back(value);
				
			while (begin != end)
			{
				this->push_back(*begin);
				++begin;
			}
		};

		template< class InputIt >
		void insert( iterator pos, InputIt first, typename std::enable_if < std::is_class <InputIt>::value, InputIt>::type last)
		{
			vector<T> temp(pos, this->end());
			iterator begin = temp.begin();
			iterator end = temp.end();
			size_type len = temp.end() - temp.begin();
			
			for (size_type i = 0; i < len; i++)
				this->pop_back();
			
			while (first != last)
			{
				push_back(*first);
				++first;
			}
			
			while (begin != end)
			{
				this->push_back(*begin);
				++begin;
			}
		};

		iterator erase( iterator pos )
		{
			return (this->erase(pos, pos + 1));
		};

		iterator erase( iterator first, iterator last )
		{
			iterator temp = last;
			iterator end = this->end();

			while (last != end)
			{
				*first = *last;
				++first;
				++last;
			}
			this->_size -= last - first;
			return (temp);
		};

		void push_back( const T& value )
		{
			if (this->_size >= this->_capacity)
				this->reserve(this->_capacity + 1);
			this->_ptr[this->_size] = value;
			this->_size++;
		};

		void pop_back()
		{
			if (this->_size > 0)
				this->_size--;
		};

		void resize( size_type count, T value = T() )
		{
			while (this->_size != count)
			{
				if (this->_size > count)
					this->pop_back();
				else
					this->push_back(value);
			}
		};

		void swap( vector& other )
		{
			vector<T> temp = *this;
			*this = other;
			other = temp;
		};
	};
};


	/* Non-member functions */

namespace ft 
{
	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);	
	};
};

template< class T, class Alloc >
bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	typename ft::vector<T>::const_iterator beg_lhs = lhs.begin();
    typename ft::vector<T>::const_iterator beg_rhs = rhs.begin();
	typename ft::vector<T>::const_iterator end_lhs = lhs.end();
    typename ft::vector<T>::const_iterator end_rhs = rhs.end();
	
	if (lhs.size() != rhs.size())
        return false;
    while (beg_lhs != end_lhs)
    {
        if (*beg_lhs != *beg_rhs)
            return false;
		beg_lhs++;
		beg_rhs++;
    }
    return true;
};

template< class T, class Alloc >
bool operator!=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
{
	if (lhs == rhs)
		return (false);
	return(true);
};

template< class T, class Alloc >
bool operator<( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
{
	typename ft::vector<T>::const_iterator beg_lhs = lhs.begin();
    typename ft::vector<T>::const_iterator beg_rhs = rhs.begin();
	typename ft::vector<T>::const_iterator end_lhs = lhs.end();
    typename ft::vector<T>::const_iterator end_rhs = rhs.end();

	while (beg_lhs != end_lhs && beg_rhs != end_rhs)
    {
        if (*beg_lhs == *beg_rhs)
        {
            beg_lhs++;
            beg_rhs++;
        }
        else
            return (*beg_lhs < *beg_rhs);
    }
    if (beg_rhs != end_rhs)
        return true;
    return false;
};

template< class T, class Alloc >
bool operator<=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
{
	return (!(rhs < lhs));
};

template< class T, class Alloc >
bool operator>( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
{
	if (lhs <= rhs)
		return (false);
	return (true);
};

template< class T, class Alloc >
bool operator>=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
{
	if (lhs < rhs)
		return (false);
	return (true);
};

#endif