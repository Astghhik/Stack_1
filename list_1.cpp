#include <iostream>
#include <cassert>
#include "list_1.hpp"


Node::Node(int data)

{

	this->data = data;

	this->next = nullptr;

}


List::List()

{

	first = nullptr;

	last = nullptr;

	int size;

}


int List::get_size()

{

	int size = 0;

	Node*n=first;

	while(n != nullptr){

		n=n->next;

		size++;

	}

	return size;

}


bool List::is_empty()

{

	return size == 0;

}


void List::push_back(int data)

{

	Node* new_node = new Node(data);

	if(is_empty())

	{

		first = new_node;

	}

	else

	{

		last->next = new_node;

	}

	last = new_node;

	size++;

}


void List::print()

{

	Node* n = first;

	while(n != nullptr)

	{

		std::cout<<n->data<<" ";

		n = n->next;

	}

	std::cout<<std::endl;

}

int& List::operator[](int position)
{
	Node* n = first;
	for(int i = 0; i < position;i++)
	{
		n = n->next;
	}
	return n->data;

}



int List::pop_back()
{
	assert(size>0);
	if (size > 1)
	{
		Node* n = first;
		Node* n_prev;
		while (n->next != nullptr)
		{
			n_prev = n;
			n = n->next;
		}
		        int d = n-> data;
			delete n;
			n_prev->next = nullptr;
			size--;
			return d;
		}
		else if (size == 1)
		{
			delete first;
			first = nullptr;
			size--;
		}
		return 0;
	
}
void List::remove_value(int value)
{
	if(is_empty())
	{
		return;
	}

	if(first->data == value)
	{
		Node* prev_node = first;
		first = first->next;
		delete prev_node;
		return;
	}

	Node* n = first;
	while(n->next != nullptr && n->next->data != value)
	{
		n = n->next;
	}

	if(n->next != nullptr)
	{
		Node* prev_node = n->next;
		n->next = n->next->next;
		delete prev_node;
	}
}

void List::remove_index(int index)
{
	assert(index >= 0 &&  index < get_size());

	if (index == 0)
	{
		Node* prev_node =first;
		first = first->next;
		delete prev_node;
		return;
	}

	Node* n= first;
	for(int i = 0; i < index-1; i++)
	{
		n = n->next;
	}

	Node* prev_node = n->next;
	n->next = n->next->next;
	delete prev_node;

	if(index == get_size() - 1)
	{
		last = n;
	}

}
void List::insert(int position, int data)
{
	assert(position >= 0 && position <= size);
	Node* element = new Node(data);
	if (position == 0)
	{
		element->next = first;
		first = element;
	}
	else
	{
		Node* n=first;
		for(int i=0;i<position -1;i++)
		{
			n =n->next;
		}
		element->next = n->next;
		n->next = element;
	}
	size++;
}
List::List(const List& object)
{ 
	Node* n_object = object.first;
	Node* prev_new = nullptr;
	while (n_object != nullptr)
	{
		Node* new_node = new Node(n_object->data);
		if(prev_new == nullptr)
		{
			first = new_node;
		}
		else
		{
			prev_new->next = new_node;
		}
		prev_new = new_node;
		n_object = n_object->next;
	}
	last = prev_new;
}

List::~List()
{
	Node* n = first;
	while (n != nullptr)
	{
		Node* next = n->next;
		delete n;
		n= next;
	}
}

bool Stack::is_empty()
{
        return index == nullptr;
}

int Stack::get_size()
{
        return size;
}


Stack::Stack()
{
	index = nullptr;
	size = 0;
}

Stack::~Stack()
{
	while(index)
	{
		Node* tmp = index;
		index = index->next;
		delete tmp;
	}
}


void Stack::push(int value)
{
	Node* new_node = new Node(value);
	new_node->next = index;
	index = new_node;
	size++;
}

int Stack::pop()
{
	if(is_empty())
	{
		return -1;
	}
	int value = index->data;
	Node* tmp = index;
	index = index->next;
	delete tmp;
	size--;
	return value;
}

int Stack::top()
{
	if(is_empty())
	{
		return -1;
	}
	return index->data;
}
