/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITList.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:59:51 by ceccentr          #+#    #+#             */
/*   Updated: 2021/02/24 11:58:33 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITLIST_HPP
# define ITLIST_HPP

# include "Node.hpp"

namespace ft
{
	template <class T>
	class ITList
	{
	private:
		node<T>* ptr;
	public:
		explicit ITList() : ptr(nullptr)
		{
		}

		explicit ITList(node<T> *ptr) : ptr(ptr)
		{
		}

		~ITList()
		{
		}

		ITList(ITList const &other)
		{
			*this = other;
		}

		ITList &operator=(const ITList &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		}

		ITList &operator++()
		{
			this->ptr = this->ptr->next;
			return (*this);
		}

		ITList &operator--()
		{
			this->ptr = this->ptr->prev;
			return (*this);
		}

		ITList operator++(int)
		{
			ITList tmp = *this;
			this->ptr = this->ptr->next;
			return (tmp);
		}

		ITList operator--(int)
		{
			ITList tmp = *this;
			this->ptr = this->ptr->prev;
			return (tmp);
		}

		bool operator==(ITList const &other)
		{
			return (this->ptr == other.ptr);
		}

		bool operator!=(ITList const &other)
		{
			return (this->ptr != other.ptr);
		}

		T &operator*()
		{
			return (*(this->ptr->data));
		}

		const T &operator*(int)
		{
			return (*(this->ptr->data));
		}

		T *operator->()
		{
			return (this->ptr->data);
		}

		node<T> *getPtr() const
		{
			return (this->ptr);
		}
	};

	template <class T>
	class ConstITList
	{
	private:

		node<T> *ptr;
		
	public:
		explicit ConstITList() : ptr(nullptr)
		{
		};

		explicit ConstITList(node<T> *ptr) : ptr(ptr)
		{
		};

		~ConstITList()
		{
		};

		ConstITList(const ConstITList &other)
		{
			*this = other;
		};

		ConstITList(const ITList<T> &other)
		{
			*this = other;
		};

		ConstITList &operator=(const ConstITList &other)
		{
			this->ptr = other.ptr;
			return (*this);
		};

		ConstITList &operator=(const ITList<T> &other)
		{
			this->ptr = other.getPtr();
			return (*this);
		};

		ConstITList &operator++()
		{
			this->ptr = this->ptr->next;
			return (*this);
		};

		ConstITList &operator--()
		{
			this->ptr = this->ptr->prev;
			return (*this);
		};

		ConstITList operator++(int)
		{
			ConstITList tmp = *this;
			this->ptr = this->ptr->next;
			return (tmp);
		};

		ConstITList operator--(int)
		{
			ConstITList tmp = *this;
			this->ptr = this->ptr->prev;
			return (tmp);
		};

		bool operator==(ConstITList const &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(ConstITList const &other)
		{
			return (this->ptr != other.ptr);
		};

		const T &operator*()
		{
			return (*(this->ptr->data));
		};
	};

	template <typename T>
	class ReverseITList
	{
	private:
		node<T> *ptr;
	public:
		explicit ReverseITList() : ptr(nullptr)
		{
		};

		explicit ReverseITList(node<T> *ptr) : ptr(ptr)
		{
		};

		~ReverseITList()
		{
		};

		ReverseITList(ReverseITList const &other)
		{
			*this = other;
		};

		ReverseITList &operator=(ReverseITList const &other)
		{
			if (this != &other)
				this->ptr = other.ptr;
			return (*this);
		};

		ReverseITList &operator++()
		{
			this->ptr = this->ptr->prev;
			return (*this);
		};

		ReverseITList &operator--()
		{
			this->ptr = this->ptr->next;
			return (*this);
		};

		ReverseITList operator++(int)
		{
			ReverseITList tmp = *this;
			this->ptr = this->ptr->prev;
			return (tmp);
		};

		ReverseITList operator--(int)
		{
			ReverseITList tmp = *this;
			this->ptr = this->ptr->next;
			return (tmp);
		};

		bool operator==(ReverseITList const &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(ReverseITList const &other)
		{
			return (this->ptr != other.ptr);
		};

		T &operator*()
		{
			return (*(this->ptr->data));
		};

		T const &operator*(int)
		{
			return (*(this->ptr->data));
		};

		T *operator->()
		{
			return (this->ptr->data);
		};

		node<T> *getPtr() const
		{
			return (this->ptr);
		};
	};

	template <typename T>
	class ConstReverseITList
	{
	private:
		node<T> *ptr;
	public:
		explicit ConstReverseITList() : ptr(nullptr)
		{
		};

		explicit ConstReverseITList(node<T> *ptr) : ptr(ptr)
		{
		};

		~ConstReverseITList()
		{
		};

		ConstReverseITList(ConstReverseITList const &other)
		{
			*this = other;
		};

		ConstReverseITList(ReverseITList<T> const &other)
		{
			*this = other;
		};

		ConstReverseITList &operator=(ConstReverseITList const &other)
		{
			this->ptr = other.ptr;
			return (*this);
		};

		ConstReverseITList &operator=(ReverseITList<T> const &other)
		{
			this->ptr = other.getPtr();
			return (*this);
		};

		ConstReverseITList &operator++()
		{
			this->ptr = this->ptr->prev;
			return (*this);
		};

		ConstReverseITList &operator--()
		{
			this->ptr = this->ptr->next;
			return (*this);
		};

		ConstReverseITList operator++(int)
		{
			ConstReverseITList tmp = *this;
			this->ptr = this->ptr->prev;
			return (tmp);
		};

		ConstReverseITList operator--(int)
		{
			ConstReverseITList tmp = *this;
			this->ptr = this->ptr->next;
			return (tmp);
		};

		bool operator==(ConstReverseITList const &other)
		{
			return (this->ptr == other.ptr);
		};

		bool operator!=(ConstReverseITList const &other)
		{
			return (this->ptr != other.ptr);
		};

		T const &operator*()
		{
			return (*(this->ptr->data));
		};

		T *operator->() const
		{
			return (this->ptr->data);
		};
	};
}

#endif