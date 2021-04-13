/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITMap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:36:16 by ceccentr          #+#    #+#             */
/*   Updated: 2021/04/06 10:49:09 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITMAP_HPP
# define ITMAP_HPP

# include <iostream>
# include "Node.hpp"

namespace ft
{
	template < class Key, class T, class Compare >
	class ITMap
	{

	public:
		typedef std::pair < const Key, T > value_type;

	private:
		map_node < Key, T > *ptr;
		Node < Key, T, Compare > head;
		
	public:
		ITMap() : ptr(nullptr)
		{
		};

		ITMap(map_node < Key, T > *ptr) : ptr(ptr)
		{
		};

		ITMap(const ITMap &other)
		{
			*this = other;
		};

		ITMap &operator=(const ITMap &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		~ITMap()
		{
		};

		map_node < Key, T > *getNode() const
		{
			return (this->ptr);
		};

		ITMap &operator++()
		{
			this->ptr = head.next_node(this->ptr);
			return (*this);
		};

		ITMap &operator--()
		{
			this->ptr = head.prev_node(this->ptr);
			return (*this);
		};

		ITMap operator++(int)
		{
			ITMap temp = *this;
			
			this->ptr = head.next_node(this->ptr);
			return (temp);
		};

		ITMap operator--(int)
		{
			ITMap temp = *this;

			this->ptr = head.prev_node(this->ptr);
			return (temp);
		};

		bool operator==(const ITMap &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(const ITMap &other)
		{
			return (this->ptr != other.ptr);
		};

		bool operator!=(const ITMap &other) const
		{
			return (this->ptr != other.ptr);
		};

		value_type &operator*()
		{
			return(*(this->ptr->data));
		};

		value_type *operator->()
		{
			return(this->ptr->data);
		};
	};

	template < class Key, class T, class Compare >
	class ConstITMap
	{

	public:
		typedef std::pair < const Key, T > value_type;

	private:
		map_node < Key, T > *ptr;
		Node < Key, T, Compare > head;
		
	public:
		ConstITMap() : ptr(nullptr)
		{
		};

		ConstITMap(map_node < Key, T > *ptr) : ptr(ptr)
		{
		};

		ConstITMap(const ConstITMap &other)
		{
			*this = other;
		};

		ConstITMap(const ITMap < Key, T, Compare > &other)
		{
			*this = other;
		};

		ConstITMap &operator=(const ConstITMap &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		ConstITMap &operator=(const ITMap < Key, T, Compare > &other)
		{
			if (this != &other)
				this->ptr = other.getNode();
			return (*this);
		};

		~ConstITMap()
		{
		};

		ConstITMap &operator++()
		{
			this->ptr = head.next_node(this->ptr);
			return (*this);
		};

		ConstITMap &operator--()
		{
			this->ptr = head.prev_node(this->ptr);
			return (*this);
		};

		ConstITMap operator++(int)
		{
			ConstITMap temp = *this;
			
			this->ptr = head.next_node(this->ptr);
			return (temp);
		};

		ConstITMap operator--(int)
		{
			ConstITMap temp = *this;

			this->ptr = head.prev_node(this->ptr);
			return (temp);
		};

		bool operator==(const ConstITMap &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(const ConstITMap &other)
		{
			return (this->ptr != other.ptr);
		};

		bool operator!=(const ConstITMap &other) const
		{
			return (this->ptr != other.ptr);
		};

		const value_type &operator*()
		{
			return(*(this->ptr->data));
		};

		value_type *operator->()
		{
			return(this->ptr->data);
		};
	};

	template < class Key, class T, class Compare >
	class ReverseITMap
	{

	public:
		typedef std::pair < const Key, T > value_type;

	private:
		map_node < Key, T > *ptr;
		Node < Key, T, Compare > head;
		
	public:
		ReverseITMap() : ptr(nullptr)
		{
		};

		ReverseITMap(map_node < Key, T > *ptr) : ptr(ptr)
		{
		};

		ReverseITMap(const ReverseITMap &other)
		{
			*this = other;
		};

		ReverseITMap &operator=(const ReverseITMap &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		~ReverseITMap()
		{
		};

		map_node < Key, T > *getNode() const
		{
			return (this->ptr);
		};

		ReverseITMap &operator++()
		{
			this->ptr = head.prev_node(this->ptr);
			return (*this);
		};

		ReverseITMap &operator--()
		{
			this->ptr = head.next_node(this->ptr);
			return (*this);
		};

		ReverseITMap operator++(int)
		{
			ReverseITMap temp = *this;
			
			this->ptr = head.prev_node(this->ptr);
			return (temp);
		};

		ReverseITMap operator--(int)
		{
			ReverseITMap temp = *this;

			this->ptr = head.next_node(this->ptr);
			return (temp);
		};

		bool operator==(const ReverseITMap &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(const ReverseITMap &other)
		{
			return (this->ptr != other.ptr);
		};

		bool operator!=(const ReverseITMap &other) const
		{
			return (this->ptr != other.ptr);
		};

		value_type &operator*()
		{
			return(*(this->ptr->data));
		};

		value_type *operator->()
		{
			return(this->ptr->data);
		};
	};

	template < class Key, class T, class Compare >
	class ConstReverseITMap
	{

	public:
		typedef std::pair < const Key, T > value_type;

	private:
		map_node < Key, T > *ptr;
		Node < Key, T, Compare > head;
		
	public:
		ConstReverseITMap() : ptr(nullptr)
		{
		};

		ConstReverseITMap(map_node < Key, T > *ptr) : ptr(ptr)
		{
		};

		ConstReverseITMap(const ConstReverseITMap &other)
		{
			*this = other;
		};

		ConstReverseITMap(const ITMap < Key, T, Compare > &other)
		{
			*this = other;
		};

		ConstReverseITMap &operator=(const ConstReverseITMap &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		ConstReverseITMap &operator=(const ITMap < Key, T, Compare > &other)
		{
			if (this != &other)
				this->ptr = other.getNode();
			return (*this);
		};

		~ConstReverseITMap()
		{
		};

		ConstReverseITMap &operator++()
		{
			this->ptr = head.next_node(this->ptr);
			return (*this);
		};

		ConstReverseITMap &operator--()
		{
			this->ptr = head.prev_node(this->ptr);
			return (*this);
		};

		ConstReverseITMap operator++(int)
		{
			ConstReverseITMap temp = *this;
			
			this->ptr = head.next_node(this->ptr);
			return (temp);
		};

		ConstReverseITMap operator--(int)
		{
			ConstReverseITMap temp = *this;

			this->ptr = head.prev_node(this->ptr);
			return (temp);
		};

		bool operator==(const ConstReverseITMap &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(const ConstReverseITMap &other)
		{
			return (this->ptr != other.ptr);
		};

		bool operator!=(const ConstReverseITMap &other) const
		{
			return (this->ptr != other.ptr);
		};

		const value_type &operator*()
		{
			return(*(this->ptr->data));
		};

		value_type *operator->()
		{
			return(this->ptr->data);
		};
	};
};

#endif