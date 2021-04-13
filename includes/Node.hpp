/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:49:43 by ceccentr          #+#    #+#             */
/*   Updated: 2021/04/13 13:52:22 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>

template <typename T>
struct node
{
	T *data;
	struct node *next;
	struct node *prev;
};

template < class Key, class T >
struct map_node
{
	struct map_node				*parent;
	struct map_node				*right;
	struct map_node				*left;
	std::pair < const Key, T >	*data;
	bool						end;
};

template < class Key, class T, class Compare = std::less<Key> , class Allocator = std::allocator <std::pair < const Key, T > > >
class Node
{
public:
	typedef Key											key_type;
	typedef T											mapped_type;
	typedef std::pair < const Key, T >					value_type;
	typedef	std::size_t									size_type;
	typedef std::ptrdiff_t								difference_type;
	typedef	Compare										key_compare;
	typedef Allocator									allocator_type;
	typedef map_node < Key, T >							node_type;
	typedef value_type&									reference;
	typedef const value_type&							const_reference;
	typedef node_type*									pointer;
	typedef const node_type*							const_pointer;

private:
	pointer			base;
	pointer			rend;
	pointer			end;
	allocator_type	alloc;
	key_compare		comp;

public:
	Node()
	{
		this->end = this->end_node(nullptr);
		this->rend = this->end_node(nullptr);
		this->base = nullptr;
	};

	Node(const allocator_type &alloc)
	{
		this->end = this->end_node(nullptr);
		this->rend = this->end_node(nullptr);
		this->base = nullptr;
		this->alloc = alloc;
	};

	Node(value_type* value)
	{
		this->base = this->new_node(value);
		this->end = this->end_node(nullptr);
		this->rend = this->end_node(nullptr);
		this->base->left = this->end;
		this->base->right = this->end;
	};

	Node(Node const &other)
	{
		*this = other;
	};

	Node &operator=(Node const &other)
	{
		if (this != &other)
		{
			this->base = other.base;
			this->alloc = other.alloc;
			this->comp = other.comp;
			if (this->base)
			{
				this->set_rend();
				this->set_end();
			}
		}
		return (*this);
	};

	~Node()
	{
		this->clear_node();
		this->alloc.deallocate(this->end->data, 1);
		delete this->end;
		this->alloc.deallocate(this->rend->data, 1);
		delete this->rend;
	};

	pointer getBase() const
	{
		return (this->base);
	};

	pointer getEnd() const
	{
		return (this->end);
	};

	pointer getRend() const
	{
		return (this->rend);
	};

	pointer new_node(const_reference value)
	{
		pointer temp = new node_type;

		temp->data = this->alloc.allocate(1);
		this->alloc.construct(temp->data, value);
		temp->parent = nullptr;
		temp->left = nullptr;
		temp->right = nullptr;
		temp->end = false;
		return (temp);
	};

	pointer end_node(pointer value)
	{
		pointer temp = new node_type;

		temp->data = this->alloc.allocate(1);
		temp->parent = value;
		temp->left = nullptr;
		temp->right = nullptr;
		temp->end = true;
		return (temp);
	};

	void set_rend()
	{
		pointer temp = this->min_node();
		
		temp->left = this->rend;
		this->rend->parent = temp;
	};

	void set_end()
	{
		pointer temp = this->max_node();
		
		temp->right = this->end;
		this->end->parent = temp;
	};

	pointer min_node(pointer head = nullptr, bool first = true) const
	{
		if (first && !head)
			head = this->base;
		if (head->left == nullptr || head->left->end)
			return (head);
		return (min_node(head->left, false));
	};

	pointer max_node(pointer head = nullptr, bool first = true) const
	{
		if (first && !head)
			head = this->base;
		if (head->right == nullptr || head->right->end)
			return (head);
		return (max_node(head->right, false));
	};

	void clear_node(pointer head = nullptr, bool first = true)
	{
		if (first)
		{
			head = this->base;
			this->base = nullptr;
		}
		if (head && !head->end)
		{
			clear_node(head->left, false);
			clear_node(head->right, false);
			this->alloc.destroy(head->data);
			this->alloc.deallocate(head->data, 1);
			delete head;
		}
	};

	pointer add_node(const_reference value, pointer head = nullptr)
	{
		pointer temp;
		
		if (this->search_node(value))
			return (nullptr);
		temp = this->new_node(value);
		if (this->base == nullptr || this->base->end)
		{
			this->base = temp;
			this->base->left = this->rend;
			this->rend->parent = this->base;
			this->base->right = this->end;
			this->end->parent = this->base;
			return (temp);
		}
		if (!head)
			head = this->base;
		while (head != nullptr && !head->end)
		{
			if (!this->comp(temp->data->first, head->data->first))
			{
				if (head->right != nullptr && !head->right->end)
					head = head->right;
				else
				{
					temp->parent = head;
					head->right = temp;
					break;
				}
			}
			else if (this->comp(temp->data->first, head->data->first))
			{
				if (head->left != nullptr && !head->left->end)
					head = head->left;
				else
				{
					temp->parent = head;
					head->left = temp;
					break;
				}
			}
		}
		set_rend();
		set_end();
		return (temp);
	};

	pointer search_node(const_reference value, pointer head = nullptr, bool first = false) const
	{
		if (!first)
			head = this->base;
		if (head == nullptr || head->end)
			return (nullptr);
		if (value.first == head->data->first)
			return (head);
		if (this->comp(value.first, head->data->first))
			return (search_node(value, head->left, true));
		else 
			return (search_node(value, head->right, true));
	};

	pointer search_node(key_type key, pointer head = nullptr, bool first = false) const
	{
		if (!first)
			head = this->base;
		if (head == nullptr || head->end)
			return (nullptr);
		if (key == head->data->first)
			return (head);
		if (this->comp(key, head->data->first))
			return (search_node(key, head->left, true));
		else 
			return (search_node(key, head->right, true));
	};

	pointer del_node(pointer head, const key_type key)
	{
		pointer temp;

			if (head == nullptr || head->end)
				return head;
			if (this->comp(key, head->data->first))
				head->left = del_node(head->left, key);
			else if (!this->comp(key, head->data->first) && key != head->data->first)
				head->right = del_node(head->right, key);
			else if (head->left != nullptr && !head->left->end && head->right != nullptr && !head->right->end)
			{
				this->alloc.destroy(head->data);
				this->alloc.deallocate(head->data, 1);
				head->data = this->alloc.allocate(1);
				this->alloc.construct(head->data, *this->min_node(head->right)->data);
				head->right = del_node(head->right, head->data->first);
			}
			else if (head->left != nullptr && !head->left->end)
			{
				if (this->base == head)
					this->base = head->left;
				temp = head->left;
				head->left->parent = head->parent;
				this->alloc.destroy(head->data);
				this->alloc.deallocate(head->data, 1);
				delete head;
				head = temp;
			}
			else if (head->right != nullptr && !head->right->end)
			{
				if (this->base == head)
					this->base = head->right;
				temp = head->right;
				head->right->parent = head->parent;
				this->alloc.destroy(head->data);
				this->alloc.deallocate(head->data, 1);
				delete head;
				head = temp;
			}
			else
			{
				if (this->base == head)
					this->base = nullptr;
				if (head->left)
					head->left->parent = head->parent;
				if (head->right)
					head->right->parent = head->parent;
				this->alloc.destroy(head->data);
				this->alloc.deallocate(head->data, 1);
				delete head;
				head = nullptr;
			}
			return (head);
	};

	pointer next_node(pointer head)
	{
		key_type key;

		if (head && head->end)
			return (head->parent);
		if (!head || head->end)
			return (head);
		if (head->right)
		{
			head = head->right;
			while (head->left)
				head = head->left;
		}
		else if (head->parent && head == head->parent->left)
			head = head->parent;
		else if (!head->left)
		{
			key = head->data->first;
			while (head->parent)
			{
				head = head->parent;
				if (this->comp(key, head->data->first))
					break;
			}
			if (!head->parent && !this->comp(key, head->data->first))
				head = head->right;
		}
		else
			head = head->right;
		return (head);		
	};

	pointer prev_node(pointer head)
	{
		key_type key;

		if (head && head->end)
			return (head->parent);
		if (!head || head->end)
			return (head);
		if (head->left)
		{
			head = head->left;
			while (head->right)
				head = head->right;
		}
		else if (head->parent && head == head->parent->right)
			head = head->parent;
		else if (!head->left)
		{
			key = head->data->first;
			while (head->parent)
			{
				head = head->parent;
				if (this->comp(key, head->data->first))
					break;
			}
			if (!head->parent && !this->comp(key, head->data->first))
				head = head->left;
		}
		else
			head = head->left;
		return (head);		
	};

};

#endif