/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:59:58 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/13 11:46:51 by ceccentr         ###   ########.fr       */
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
		void insert( iterator pos, InputIt first, typename std::enable_if < std::is_class <InputIt>::value, InputIt>::type last)
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
				this->_end->prev = del_node->prev;
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
			{
				this->_begin->prev = new_node;
				new_node->next = this->_begin;
			}
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

			back_node = this->_end->prev;
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

			back_node = this->_end->prev;
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
			iterator it_this = this->begin();
			iterator it_other = other.begin();
			iterator temp(it_other);

			if (this == &other)
				return ;
			while (it_other != other.end())
			{
				temp++;
				while (it_this != this->end())
				{
					if (*it_other < *it_this)
					{
						this->splice(it_this, other, it_other);
						break;
					}
					else
						it_this++;
				}
				if (it_this == this->end())
					this->splice(it_this, other, it_other);
				it_other = temp;
    		}
		};

		template <class Compare>
		void merge( list& other, Compare comp )
		{
			iterator it_this = this->begin();
			iterator it_other = other.begin();
			iterator temp(it_other);

			if (this == &other)
				return ;
			while (it_other != other.end())
			{
				temp++;
				while (it_this != this->end())
				{
					if (comp(*it_other, *it_this))
					{
						this->splice(it_this, other, it_other);
						break;
					}
					else
						it_this++;
				}
				if (it_this == this->end())
					this->splice(it_this, other, it_other);
				it_other = temp;
    		}
		};

		void splice( iterator pos, list& other )
		{
			this->splice(pos, other, other.begin(), other.end());
		};

		void splice( iterator pos, list& other, iterator it )
		{
			node<T> *it_node = it.getPtr();
			node<T> *pos_node = pos.getPtr();
			
			if (it_node != other._end)
			{
				it_node->prev->next = it_node->next;
				it_node->next->prev = it_node->prev;
				other._begin = other._end->next;
				other._size--;
				pos_node->prev->next = it_node;
				it_node->prev = pos_node->prev;
				pos_node->prev = it_node;
				it_node->next = pos_node;
				this->_begin = this->_end->next;
				this->_size++;
			}
		};

		void splice( iterator pos, list& other, iterator first, iterator last)
		{
			node<T>		*first_node = first.getPtr();
			node<T>		*last_node = last.getPtr();
			node<T>		*pos_node = pos.getPtr();
			size_type	count = 0;

			for (iterator temp = first; temp != last; temp++)
				count++;
			if (first_node != other._end)
			{
				if (last_node == other._end)
					last_node = last_node->prev;
				first_node->prev->next = last_node->next;
				last_node->next->prev = first_node->prev;
				other._begin = other._end->next;
				other._size -= count;
				pos_node->prev->next = first_node;
				first_node->prev = pos_node->prev;
				pos_node->prev = last_node;
				last_node->next = pos_node;
				this->_begin = this->_end->next;
				this->_size += count;
          	}
		};

		void remove( const T& value )
		{
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if (*it == value)
					it = this->erase(it);
			}
		};

		template< class UnaryPredicate >
		void remove_if( UnaryPredicate p )
		{
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if (p(*it))
					it = this->erase(it);
			}
		};

		void reverse()
		{
			list temp;

			for (iterator it = this->begin(); it != this->end(); it++)
			{
				temp.push_front(*it);
			}
			*this = temp;
		};

		void unique()
		{
			iterator	beg = this->begin();
			iterator	end = this->end();
			node<T>		*temp;

			++beg;
			while (beg != end)
			{
				temp = beg.getPtr()->prev;
				if (*beg == *temp->data)
					beg = this->erase(beg);
				else
					++beg;		
			}
		};

		template< class BinaryPredicate >
		void unique( BinaryPredicate p )
		{
			iterator	beg = this->begin();
			iterator	end = this->end();
			node<T>		*temp;

			++beg;
			while (beg != end)
			{
				temp = beg.getPtr()->prev;
				if (p(*beg, *temp->data))
					beg = this->erase(beg);
				else
					++beg;		
			}
		};

		void sort()
		{
			iterator beg = this->begin();
			iterator next = this->begin();
			iterator end = this->end();

			while (++next != end)
			{
				if (*next < *beg)
				{
					this->splice(beg, *this, next);
					beg = this->begin();
					next = this->begin();
				}
				else
					beg = next;
			}
		};

		template< class Compare >
		void sort( Compare comp )
		{
			iterator beg = this->begin();
			iterator next = this->begin();
			iterator end = this->end();

			while (++next != end)
			{
				if (comp(*next,*beg))
				{
					this->splice(beg, *this, next);
					beg = this->begin();
					next = this->begin();
				}
				else
					beg = next;
			}
		};
	};
}

	/* Non-member functions */
	
namespace ft 
{
	template< class T, class Alloc >
	void swap( ft::list<T,Alloc>& lhs,ft::list<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	};
}

template< class T, class Alloc >
bool operator==( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	typename ft::list<T>::const_iterator beg_lhs = lhs.begin();
    typename ft::list<T>::const_iterator beg_rhs = rhs.begin();
	typename ft::list<T>::const_iterator end_lhs = lhs.end();
    typename ft::list<T>::const_iterator end_rhs = rhs.end();
	
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
bool operator!=( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	if (lhs == rhs)
		return (false);
	return(true);
};

template< class T, class Alloc >
bool operator<( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	typename ft::list<T>::const_iterator beg_lhs = lhs.begin();
    typename ft::list<T>::const_iterator beg_rhs = rhs.begin();
	typename ft::list<T>::const_iterator end_lhs = lhs.end();
    typename ft::list<T>::const_iterator end_rhs = rhs.end();

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
bool operator<=( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	return (!(rhs < lhs));
};

template< class T, class Alloc >
bool operator>( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	if (lhs <= rhs)
		return (false);
	return (true);
};

template< class T, class Alloc >
bool operator>=( const ft::list<T,Alloc>& lhs,const ft::list<T,Alloc>& rhs )
{
	if (lhs < rhs)
		return (false);
	return (true);
};

#endif