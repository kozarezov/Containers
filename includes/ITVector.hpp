/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:35:14 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/19 11:00:52 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITVECTOR_HPP
# define ITVECTOR_HPP

# include <iostream>

namespace ft
{
	template <typename T>
	class ITVector
	{
	public:
		typedef std::ptrdiff_t difference_type;

	private:
		T *ptr;
	public:
		ITVector() : ptr(nullptr)
		{
		};

		ITVector(T *ptr) : ptr(ptr)
		{
		};

		ITVector(ITVector const &other)
		{
			*this = other;
		};

		ITVector &operator=(ITVector const &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		~ITVector()
		{
		};

		T *getPtr() const
		{
			return (this->ptr);
		};

		ITVector &operator++()
		{
			++this->ptr;
			return (*this);
		};

		ITVector &operator--()
		{
			--this->ptr;
			return (*this);
		};

		ITVector operator++(int)
		{
			ITVector tmp = *this;
			
			++this->ptr;
			return (tmp);
		};

		ITVector operator--(int)
		{
			ITVector tmp = *this;

			--this->ptr;
			return (*this);
		};

		bool operator==(ITVector const &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(ITVector const &other)
		{
			return (this->ptr != other.ptr);
		};

		ITVector operator+(difference_type n)
		{
			return (ITVector(this->ptr + n));
		};

		ITVector operator-(difference_type n)
		{
			return (ITVector(this->ptr - n));
		};

		difference_type operator-(const ITVector &it)
		{
			return (this->ptr - it.ptr);
		};

		ITVector &operator-=(difference_type n)
		{
			this->ptr -= n;
			return (*this);
		};

		ITVector &operator+=(difference_type n)
		{
			this->ptr += n;
			return (*this);
		};

		T &operator[](difference_type n)
		{
			return (this->ptr[n]);
		};

		T &operator*()
		{
			return (*(this->ptr));
		};

		T *operator->()
		{
			return (this->ptr);
		};
	};

	template <typename T>
	class ConstITVector
	{
	public:
		typedef std::ptrdiff_t difference_type;

	private:
		T *ptr;
	public:
		explicit ConstITVector() : ptr(nullptr)
		{
		};

		explicit ConstITVector(T *ptr) : ptr(ptr)
		{
		};

		ConstITVector(ConstITVector const &other)
		{
			*this = other;
		};

		ConstITVector(ITVector<T> const &other)
		{
			*this = other;
		};

		ConstITVector &operator=(ConstITVector const &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		ConstITVector &operator=(ITVector<T> const &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		~ConstITVector()
		{
		};

		ConstITVector &operator++()
		{
			++this->ptr;
			return (*this);
		};

		ConstITVector &operator--()
		{
			--this->ptr;
			return (*this);
		};

		ConstITVector operator++(int)
		{
			ConstITVector tmp = *this;
			
			++this->ptr;
			return (tmp);
		};

		ConstITVector operator--(int)
		{
			ConstITVector tmp = *this;

			--this->ptr;
			return (*this);
		};

		bool operator==(ConstITVector const &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(ConstITVector const &other)
		{
			return (this->ptr != other.ptr);
		};

		ConstITVector operator+(difference_type n) const
		{
			return (ConstITVector(this->ptr + n));
		};

		ConstITVector operator-(difference_type n) const
		{
			return (ConstITVector(this->ptr - n));
		};

		difference_type operator-(const ConstITVector &it) const
		{
			return (ConstITVector(this->ptr-it.ptr));
		};

		ConstITVector &operator-=(difference_type n)
		{
			this->ptr -= n;
			return (*this);
		};

		ConstITVector &operator+=(difference_type n)
		{
			this->ptr += n;
			return (*this);
		};

		T &operator[](difference_type n) const
		{
			return (this->ptr[n]);
		};

		const T &operator*()
		{
			return (*(this->ptr));
		};

		T *operator->()
		{
			return (this->ptr);
		};
	};

		template <typename T>
	class ReverseITVector
	{
	public:
		typedef std::ptrdiff_t difference_type;
		
	private:
		T *ptr;
	public:
		explicit ReverseITVector() : ptr(nullptr)
		{
		};

		explicit ReverseITVector(T *ptr) : ptr(ptr)
		{
		};

		ReverseITVector(ReverseITVector const &other)
		{
			*this = other;
		};

		ReverseITVector &operator=(ReverseITVector const &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		~ReverseITVector()
		{
		};

		T *getPtr() const
		{
			return (this->ptr);
		};

		ReverseITVector &operator++()
		{
			--this->ptr;
			return (*this);
		};

		ReverseITVector &operator--()
		{
			++this->ptr;
			return (*this);
		};

		ReverseITVector operator++(int)
		{
			ReverseITVector tmp = *this;
			
			--this->ptr;
			return (tmp);
		};

		ReverseITVector operator--(int)
		{
			ReverseITVector tmp = *this;

			++this->ptr;
			return (*this);
		};

		bool operator==(ReverseITVector const &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(ReverseITVector const &other)
		{
			return (this->ptr != other.ptr);
		};

		ReverseITVector operator+(difference_type n)
		{
			return (ReverseITVector(this->ptr - n));
		};

		ReverseITVector operator-(difference_type n)
		{
			return (ITReverseITVectorVector(this->ptr + n));
		};

		difference_type operator-(const ReverseITVector &it)
		{
			return (ReverseITVector(this->ptr - it.ptr));
		};

		ReverseITVector &operator-=(difference_type n)
		{
			this->ptr += n;
			return (*this);
		};

		ReverseITVector &operator+=(difference_type n)
		{
			this->ptr -= n;
			return (*this);
		};

		T &operator[](difference_type n)
		{
			return (this->ptr[n]);
		};

		T &operator*()
		{
			return (*(this->ptr));
		};

		T *operator->()
		{
			return (this->ptr);
		};
	};

	template <typename T>
	class ConstReverseITVector
	{
	public:
		typedef std::ptrdiff_t difference_type;
		
	private:
		T *ptr;
	public:
		explicit ConstReverseITVector() : ptr(nullptr)
		{
		};

		explicit ConstReverseITVector(T *ptr) : ptr(ptr)
		{
		};

		ConstReverseITVector(ConstReverseITVector const &other)
		{
			*this = other;
		};

		ConstReverseITVector(ReverseITVector<T> const &other)
		{
			*this = other;
		};

		ConstReverseITVector &operator=(ConstReverseITVector const &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		ConstReverseITVector &operator=(ReverseITVector<T> const &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		~ConstReverseITVector()
		{
		};

		ConstReverseITVector &operator++()
		{
			--this->ptr;
			return (*this);
		};

		ConstReverseITVector &operator--()
		{
			++this->ptr;
			return (*this);
		};

		ConstReverseITVector operator++(int)
		{
			ConstReverseITVector tmp = *this;
			
			--this->ptr;
			return (tmp);
		};

		ConstReverseITVector operator--(int)
		{
			ConstReverseITVector tmp = *this;

			++this->ptr;
			return (*this);
		};

		bool operator==(ConstReverseITVector const &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(ConstReverseITVector const &other)
		{
			return (this->ptr != other.ptr);
		};

		ConstReverseITVector operator+(difference_type n) const
		{
			return (ConstReverseITVector(this->ptr - n));
		};

		ConstReverseITVector operator-(difference_type n) const
		{
			return (ConstReverseITVector(this->ptr + n));
		};

		difference_type operator-(const ConstReverseITVector &it) const
		{
			return (ConstReverseITVector(this->ptr - it.ptr));
		};

		ConstReverseITVector &operator-=(difference_type n)
		{
			this->ptr += n;
			return (*this);
		};

		ConstReverseITVector &operator+=(difference_type n)
		{
			this->ptr -= n;
			return (*this);
		};

		T &operator[](difference_type n) const
		{
			return (this->ptr[n]);
		};

		const T &operator*()
		{
			return (*(this->ptr));
		};

		T *operator->()
		{
			return (this->ptr);
		};
	};
};

#endif