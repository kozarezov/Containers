/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:32:37 by ceccentr          #+#    #+#             */
/*   Updated: 2021/04/13 15:40:21 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <limits>
# include "Node.hpp"
# include "ITMap.hpp"

namespace ft
{
	template <
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
	> 
	
	class map
	{
	
	public:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef std::pair < const Key, T >								value_type;
		typedef	std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;
		typedef	Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename ft::ITMap < Key, T, Compare >					iterator;
		typedef typename ft::ConstITMap < Key, T, Compare >				const_iterator;
		typedef typename ft::ReverseITMap < Key, T, Compare >			reverse_iterator;
		typedef typename ft::ConstReverseITMap < Key, T, Compare >		const_reverse_iterator;

	private:
		Node < key_type, mapped_type, key_compare, allocator_type >			_head;
		allocator_type														_alloc;
		key_compare															_comp;
		size_type															_size;

		/* https://en.cppreference.com/w/cpp/container/map/value_compare */
		template <class Cmp>
		class value_compare
		{
			friend class map;
		protected:
			Cmp comp;
			value_compare(Cmp c) : comp(c)
			{
			};
			
		public:
			typedef bool result_type;
			typedef std::pair<const Key, T> first_argument_type;
			typedef std::pair<const Key, T> second_argument_type;
			bool operator()(const first_argument_type &lhs, const second_argument_type &rhs) const
			{
				return comp(lhs.first, rhs.first);
			};
		};
		
	public:
		explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _head(alloc), _alloc(alloc), _comp(comp)
		{
			this->_size = 0;
		};

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _head(alloc), _alloc(alloc), _comp(comp)
		{
			this->_size = 0;
			this->insert(first, last);
		};

		map( const map& other )
		{
			*this = other;
		};

		map &operator=(const map &other) 
		{
			this->clear();
			this->_comp = other._comp;
			this->_alloc = other._alloc;
			const_iterator beg = other.begin();
			const_iterator end = other.end();
			while (beg != end)
			{
				this->insert(*beg);
				++beg;
			}
			return (*this);
		};

		~map()
		{
		};

		T& operator[]( const Key& key ) 
		{
			map_node < Key, T > *tmp = this->_head.search_node(key);
			if (!tmp)
			{
				this->_size++;
				return ((this->_head.add_node(std::pair < key_type, mapped_type >(key, T())))->data->second);
			}
			return (tmp->data->second);
		};

		iterator begin()
		{ 
			if (this->_size == 0)
				return (this->end());
			return iterator(this->_head.min_node()); 
		};

		const_iterator begin() const 
		{ 	
			if (this->_size == 0)
				return (this->end());
			return const_iterator(this->_head.min_node());
		};

		iterator end()
		{
			return iterator(this->_head.getEnd());
		};

		const_iterator end() const
		{
			return const_iterator(this->_head.getEnd());
		};

		reverse_iterator rbegin() 
		{ 	
			if (this->_size == 0)
				return (this->rend());
			return reverse_iterator(this->_head.max_node());
		};

		const_reverse_iterator rbegin() const
		{ 	
			if (this->_size == 0)
				return (this->rend());
			return const_reverse_iterator(this->_head.max_node());
		};

		reverse_iterator rend()
		{
			return reverse_iterator(this->_head.getRend());
		};

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->_head.getRend());
		};

		bool empty() const 
		{
			return (this->_size == 0);
		};

		size_type size(void) const 
		{
			return (this->_size);
		};

		size_type max_size(void) const 
		{ 
			return (std::numeric_limits<size_type>::max() / sizeof(Node < Key, T >) / 2);
		};

		void clear()
		{
			this->_size = 0;
			this->_head.clear_node();
		};

		std::pair<iterator, bool> insert( const value_type& value )
		{
			if (!this->_head.search_node(value))
			{
				this->_size++;
				return(std::pair < iterator, bool > (iterator(this->_head.add_node(value)), true));
			}
			else
				return (std::pair < iterator, bool > (iterator(this->_head.search_node(value)), false));
		};

		iterator insert( iterator hint, const value_type& value )
		{
			(void)(hint);
			if (!this->_head.search_node(value))
			{
				this->_size++;
				return(iterator(this->_head.add_node(value)));
			}
			else
				return (iterator(this->_head.search_node(value)));
		};

		template< class InputIt >
		void insert( InputIt first, InputIt last )
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		};

		void erase( iterator pos )
		{
			if (this->_size)
			{
				this->_head.del_node(this->_head.getBase(), (*pos).first);
				this->_head.set_end();
				this->_head.set_rend();
				this->_size--;
			}
		};

		void erase( iterator first, iterator last )
		{
			iterator temp = first;

			while (first != last)
			{
				temp++;
				this->_head.del_node(this->_head.getBase(), (*first).first);
				this->_size--;
				first = temp;
			}
		};	

		size_type erase( const key_type& key )
		{
			map_node < Key, T > *temp = this->_head.search_node(key);

			if (temp)
			{
				this->_head.del_node(this->_head.getBase(), key);
				this->_head.set_end();
				this->_head.set_rend();
				this->_size--;
				return(1);
			}
			else 
				return(0);
		};

		void swap( map& other )
		{
			map < Key, T, Compare, Allocator > temp = *this;
			*this = other;
			other = temp;
		};

		size_type count( const Key& key ) const
		{
			if (this->_head.search_node(key))
				return(1);
			else
				return(0);
		};

		iterator find( const Key& key )
		{
			map_node < Key, T > *temp;

			temp = this->_head.search_node(key);
			if (!temp)
				return (this->end());
			return (iterator(temp));
		};

		const_iterator find( const Key& key ) const
		{
			map_node < Key, T > *temp;

			temp = this->_head.search_node(key);
			if (!temp)
				return (this->end());
			return (const_iterator(temp));
		};

		std::pair<iterator,iterator> equal_range( const Key& key )
		{
			return (std::pair < iterator, iterator > (this->lower_bound(key), this->upper_bound(key)));
		};

		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{
			return (std::pair < const_iterator, const_iterator > (this->lower_bound(key), this->upper_bound(key)));
		};

		iterator lower_bound( const Key& key )
		{
			map_node < Key, T > *temp;

			temp = this->_head.search_node(key);
			if (temp)
				return (iterator(temp));
			iterator beg = this->begin();
			iterator end = this->end();
			while (beg != end)
			{
				if (!this->_comp((*beg).first, key))
					return (beg);
				beg++;
			}
			return(iterator(this->_head.getBase()));
		};

		const_iterator lower_bound( const Key& key ) const
		{
			map_node < Key, T > *temp;

			temp = this->_head.search_node(key);
			if (temp)
				return (const_iterator(temp));
			iterator beg = this->begin();
			iterator end = this->end();
			while (beg != end)
			{
				if (!this->_comp((*beg).first, key))
					return (beg);
				beg++;
			}
			return(const_iterator(this->_head.getBase()));
		};

		iterator upper_bound( const Key& key )
		{
			iterator beg = this->begin();
			iterator end = this->end();
			while (beg != end)
			{
				if (this->_comp(key, (*beg).first))
					break;
				beg++;
			}
			return (beg);
		};

		const_iterator upper_bound( const Key& key ) const
		{
			const_iterator beg = this->begin();
			const_iterator end = this->end();
			while (beg != end)
			{
				if (this->_comp(key, (*beg).first))
					break;
				beg++;
			}
			return (beg);
		};

		key_compare key_comp() const
		{
			return (this->_comp);
		};

		value_compare < key_compare > value_comp() const 
		{

			return (value_compare < key_compare > (this->_comp));
		};
	};
}

namespace ft 
{
	template < class Key, class T, class Compare, class Alloc >
	void swap(ft::map<Key, T, Compare, Alloc > &lhs, ft::map<Key, T, Compare, Alloc > &rhs) 
	{
		lhs.swap(rhs);
	};
}

template< class Key, class T, class Compare, class Alloc >
bool operator==( const ft::map < Key,T,Compare,Alloc > & lhs, const ft::map < Key,T,Compare,Alloc > & rhs )
{
	typename ft::map<Key, T, Compare, Alloc >::const_iterator beg_lhs = lhs.begin();
	typename ft::map<Key, T, Compare, Alloc >::const_iterator beg_rhs = rhs.begin();
	typename ft::map<Key, T, Compare, Alloc >::const_iterator end_lhs = lhs.end();
	typename ft::map<Key, T, Compare, Alloc >::const_iterator end_rhs = rhs.end();
	
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

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const ft::map < Key,T,Compare,Alloc > & lhs, const ft::map < Key,T,Compare,Alloc > & rhs )
{
	if (lhs == rhs)
		return (false);
	return(true);
};

template < class Key, class T, class Compare, class Alloc >
bool operator<(const ft::map < Key, T, Compare, Alloc > &lhs, const ft::map < Key, T, Compare, Alloc > &rhs)
{
	typename ft::map<Key, T, Compare, Alloc >::const_iterator beg_lhs = lhs.begin();
	typename ft::map<Key, T, Compare, Alloc >::const_iterator beg_rhs = rhs.begin();
	typename ft::map<Key, T, Compare, Alloc >::const_iterator end_lhs = lhs.end();
	typename ft::map<Key, T, Compare, Alloc >::const_iterator end_rhs = rhs.end();
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

template < class Key, class T, class Compare, class Alloc >
bool operator<=(const ft::map < Key, T, Compare, Alloc > &lhs, const ft::map < Key, T, Compare, Alloc > &rhs)
{
	return (!(rhs < lhs));
};

template < class Key, class T, class Compare, class Alloc >
bool operator>(const ft::map < Key, T, Compare, Alloc > &lhs, const ft::map < Key, T, Compare, Alloc > &rhs)
{
	if (lhs <= rhs)
		return (false);
	return (true);
};

template < class Key, class T, class Compare, class Alloc >
bool operator>=(const ft::map < Key, T, Compare, Alloc > &lhs, const ft::map < Key, T, Compare, Alloc > &rhs)
{
	if (lhs < rhs)
		return (false);
	return (true);
};

#endif