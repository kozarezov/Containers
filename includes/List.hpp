/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:59:58 by ceccentr          #+#    #+#             */
/*   Updated: 2021/01/27 13:19:52 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <limits>
# include "ITList.hpp"

/* https://en.cppreference.com/w/cpp/container/list */

namespace ft 
{
	template < typename T, typename Alloc = std::allocator<T> >
	class list
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
		typedef typename ft::ITList<T>						iterator;
		typedef typename ft::ConstITList<T>					const_iterator;
		typedef typename ft::ReverseITList<T>				reverse_iterator;
		typedef typename ft::ConstReverseITList<T>			const_reverse_iterator;
	
	private:
		node<value_type>			*_begin;
		node<value_type>			*_end;
		size_type					_size;
		allocator_type				_alloc;
		std::allocator< node<T> >	_node;

	public:
	/* My functions */
		node<T> *add_node(const T& value)
		{
			node<T> *new_node;
			
			new_node = this->_node.allocate(1);
			this->_node.construct(new_node);
			new_node->data = this->_alloc.allocate(1);
			this->_alloc.construct(new_node->data, value);
			return (new_node);
		};
		
		void	delete_node(node<T> *del_node)
		{
			this->_alloc.destroy(del_node->data);
			this->_alloc.deallocate(del_node->data, 1);
			this->_node.destroy(del_node);
			this->_node.deallocate(del_node, 1);
		};
		
	/* Member functions */
		list()
		{
			this->_size = 0;
			this->_end = this->_node.allocate(1);
			this->_node.construct(this->_end);
			this->_end->data = new T();
			this->_end->next = this->_end;
			this->_end->prev = this->_end;
			this->_begin = this->_end;
		};
		
		explicit list(const Alloc &alloc)
		{
			this->_alloc = alloc;
			this->_size = 0;
			this->_end = this->_node.allocate(1);
			this->_node.construct(this->_end);
			this->_end->data = new T();
			this->_end->next = this->_end;
			this->_end->prev = this->_end;
			this->_begin = this->_end;
		};

		explicit list(size_type count, const T &value = T(), const Alloc &alloc = Alloc())
		{
			this->_alloc = alloc;
			this->_size = 0;
			this->_end = this->_node.allocate(1);
			this->_node.construct(this->_end);
			this->_end->data = new T();
			this->_end->next = this->_end;
			this->_end->prev = this->_end;
			this->_begin = this->_end;
			this->assign(count, value);
		};

		template< class InputIt >
		list(InputIt first, typename std::enable_if < std::is_class <InputIt>::value, InputIt>::type last, const Alloc &alloc = Alloc())
		{
			this->_alloc = alloc;
			this->_size = 0;
			this->_end = this->_node.allocate(1);
			this->_node.construct(this->_end);
			this->_end->data = new T();
			this->_end->next = this->_end;
			this->_end->prev = this->_end;
			this->_begin = this->_end;
			this->assign(first, last);
		};

		list (const list &other)
		{
			this->_alloc = other._alloc;
			this->_size = 0;
			this->_end = this->_node.allocate(1);
			this->_node.construct(this->_end);
			this->_end->data = new T();
			this->_end->next = this->_end;
			this->_end->prev = this->_end;
			this->_begin = this->_end;
			this->assign(other.begin(), other.end());
		};

		~list()
		{
			this->clear();
			delete this->_end->data;
			this->_node.destroy(this->_end);
			this->_node.deallocate(this->_end, 1);
		};

		list &operator=(const list &other)
		{
			this->clear();
			if (other.empty() || (this == &other))
				return (*this);
			this->assign(other.begin(), other.end());
			return (*this);
		};

		void assign( size_type count, const T& value )
		{
			this->clear();
			for (size_type i = 0; i < count; i++)
				push_back(value);
		};

		template< class InputIt >
		void assign( InputIt first, typename std::enable_if < std::is_class <InputIt>::value, InputIt>::type last )
		{
			this->clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		};
	/* Element access */
		reference front() 
		{
			return (*this->_begin->data);
		};

		const_reference front() const 
		{
			return (*this->_begin->data);
		};

		reference back() 
		{
			return (*this->_end->prev->data);
		};

		const_reference back() const 
		{
			return (*this->_end->prev->data);
		};

	/* Iterators */
		iterator begin()
		{
			return (iterator(this->_begin));
		};

		const_iterator begin() const
		{
			return (const_iterator(this->_begin));
		};

		iterator end()
		{
			return (iterator(this->_end));
		};

		const_iterator end() const
		{
			return (const_iterator(this->_end));
		};

		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->_end->prev));
		};

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->_end->prev));
		};

		reverse_iterator rend()
		{
			return (reverse_iterator(this->_end));
		};

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->_end));
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
			return (std::numeric_limits<size_type>::max() / sizeof(node<T>));
		};

	/* Modifiers */
		void clear()
		{
			while (this->_size)
				this->pop_back();
		};

		iterator insert( iterator pos, const T& value )
		{
			node<T> *new_node;
			
			new_node = this->add_node(value);
			new_node->prev = pos.getPtr()->prev;
			if (new_node->prev == this->_end)
				this->_begin = new_node;
			new_node->next = pos.getPtr();
			if (new_node->next == this->_end)
				this->_end->prev = new_node;
			new_node->prev->next = new_node;
			new_node->next->prev = new_node;
			this->_size++;
			return (iterator(new_node));
		};

		void insert( iterator pos, size_type count, const T& value )
		{
			for (size_type i = 0; i < count; i++)
			{
				this->insert(pos, value);
			}
		};

		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last)
		{
			while (first != last)
			{
				this->insert(pos, *first);
				++first;
			}
		};

		iterator erase( iterator pos )
		{
			node<T> *del_node;

			del_node = pos.getPtr();
			if (del_node == this->_end)
				return (iterator(this->_end));
			del_node->prev->next = del_node->next;
			del_node->next->prev = del_node->prev;
			pos++;
			this->delete_node(del_node);
			this->_size--;
			if (del_node->prev == this->_end)
				this->_begin = del_node->next;
			if (del_node->next == this->_end)
				this->_back = del_node->prev;
			return (pos);
		};

		iterator erase( iterator first, iterator last )
		{
			while (first != last)
				first = this->erase(first);
			return (first);
		};

		void push_front( const T& value )
		{
			node<T> *new_node;

			new_node = this->add_node(value);
			new_node->prev = this->_end;
			if (this->_begin == this->_end)
			{
				new_node->next = this->_end;
				this->_end->prev = new_node;
			}
			else
				new_node->next = this->_begin;
			this->_begin = new_node;
			this->_end->next = this->_begin;
			this->_size++;
		};

		void pop_front()
		{
			node<T> *temp;

			if (this->_begin != this->_end)
			{
				temp = this->_begin->next;
				this->delete_node(this->_begin);
				this->_size--;
				if (temp == this->_end)
				{
					this->_begin = this->_end;
					this->_end->prev = this->_end;
				}
				else
				{
					this->_begin = temp;
					this->_begin->prev = this->_end;
				}
			}
		};

		void push_back( const T& value )
		{
			node<T> *back_node;
			node<T> *new_node;

			back_node = this->_end->prev.getPtr();
			new_node = add_node(value);
			new_node->next = this->_end;
			this->_end->prev = new_node;
			this->_size++;
			if (back_node == this->_end)
			{
				this->_begin = new_node;
				new_node->prev = this->_end;
				this->_end->next = new_node;
			}
			else
			{
				back_node->next = new_node;
				new_node->prev = back_node;
			}
		};

		void pop_back()
		{
			node<T> *back_node;
			node<T> *temp;

			back_node = this->_end->prev.getPtr();
			if (back_node != this->_end)
			{
				temp = back_node->prev;
				this->delete_node(back_node);
				this->_size--;
				if (temp == this->_end)
				{
					this->_begin = this->_end;
					this->_end->prev = this->_end;
				}
				else
				{
					temp->next = this->_end;
					this->_end->prev = temp;
				}
			}
		};

		void resize( size_type count, T value = T() )
		{
			if (this->_size != count)
			{
				while (this->_size != count)
				{
					if (this->_size < count)
						this->push_back(value);
					else
						this->pop_back();
				}
			}
		};

		void swap( list& other )
		{
			list temp = *this;
			*this = other;
			other = temp;
		};

	/* Operations */
		void merge( list& other )
		{
			iterator begin_other = other.begin();
			iterator end_other = other.end();
			iterator begin_this = this->begin();
			iterator end_this = this->end();

			if (*this != other)
			{
				
			}
		};

		template <class Compare>
		void merge( list& other, Compare comp )
		{
			iterator begin_other = other.begin();
			iterator end_other = other.end();
			iterator begin_this = this->begin();
			iterator end_this = this->end();

			if (*this != other)
			{
				while (begin_this != end_this && begin_other != end_other)
				{
					while (begin_this != end_this && !comp(*begin_other, *begin_this))
						++begin_this;
					++begin_other;
					this->splice(begin_this, other, begin_other.ptr->prev);
				}
			}
		};

		void splice( const_iterator pos, list& other )
		{
			/*  write */
		};

		void splice( const_iterator pos, list& other, const_iterator it )
		{
			/*  write */
		};

		void splice( const_iterator pos, list& other, const_iterator first, const_iterator last)
		{
			/*  write */
		};

		void remove( const T& value )
		{
			/*  write */
		};

		template< class UnaryPredicate >
		void remove_if( UnaryPredicate p )
		{
			/*  write */
		};

		void reverse()
		{
			/*  write */
		};

		void unique()
		{
			/*  write */
		};

		template< class BinaryPredicate >
		void unique( BinaryPredicate p )
		{
			/*  write */
		};

		void sort()
		{
			/*  write */
		};

		template< class Compare >
		void sort( Compare comp )
		{
			/*  write */
		};
	};
}

	/* Non-member functions */
namespace ft 
{
	template< class T, class Alloc >
	void swap( ft::list<T,Alloc>& lhs,ft::list<T,Alloc>& rhs )
	{
		/*  write */
	};
}

template< class T, class Alloc >
bool operator==( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	/*  write */
};

template< class T, class Alloc >
bool operator!=( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	/*  write */
};

template< class T, class Alloc >
bool operator<( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	/*  write */
};

template< class T, class Alloc >
bool operator<=( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	/*  write */
};

template< class T, class Alloc >
bool operator>( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	/*  write */
};

template< class T, class Alloc >
bool operator>=( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	/*  write */
};

#endif