#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"

Node* LinkedList::createNode(const char* data1, Node* next1)
{
	Node* ptr = new Node;
	ptr->setData(data1);
	ptr->setNext(next1);
	++size;
	return ptr;
}

Node* LinkedList::get(int index) const
{
	if (index > size || index < 1)
	{
		return 0;
	}
	Node* ptr = head;
	for (int i = 1; i < index; ++i)
	{
		ptr = ptr->getNext();
	}
	return ptr;
}

LinkedList::LinkedList()
{
	size = 0;
	tail = NULL;
	head = NULL;
}

LinkedList::LinkedList(const LinkedList& other): LinkedList()
{
	for (int i = 1; i <= other.size; ++i)
	{
		append(other.at(i));
	}
}

LinkedList::~LinkedList()
{
	int newSize = size;
	for (int i = 1; i <= newSize; ++i)
	{
		remove(1);
	}

}

void LinkedList::prepend(const char* data1)
{
	Node* newnode = createNode(data1,head);
	head = newnode;
}

void LinkedList::append(const char* data1)
{
	Node* ptr = head;
	for (int i = 1; i < size; ++i)
	{
		ptr = ptr->getNext();
	}
	tail = ptr;
	Node* newnode = createNode(data1,nullptr);
	if (size == 1) // checking if the list was empty
	{
		head = newnode;
		tail = newnode;
		return;
	}
	tail->setNext(newnode);
	tail = newnode;

}

void LinkedList::insert(const char* data1, int index)
{
	if (!(size >= index - 1))
	{
		return;
	}
	if (index == 1)
	{
		prepend(data1);
		return;
	}
	Node* newnode = createNode(data1);
	Node* ptr = get(index - 1);
	newnode->setNext(ptr->getNext());
	ptr->setNext(newnode);
}

void LinkedList::remove(int index)
{
	if (index > size || index < 1)
	{
		return;
	}
	else if (index == 1)
	{
		Node* ptr = head;
		head=head->getNext();
		delete ptr;
		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
	}
	else if (index == size)
	{
		Node* ptr = get(index - 1);
		delete tail;
		ptr->setNext(nullptr);
		tail = ptr;
	}
	else
	{
		Node* ptr = get(index);
		Node* ptr1 = get(index - 1);
		ptr1->setNext(ptr->getNext());
		delete ptr;
	}
	--size;
}

bool LinkedList::contains(const char* value) const
{
	Node* ptr = head;
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(ptr->getData(), value) == 0)
		{
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;
}

bool LinkedList::isEmpty() const
{
	if (head == nullptr && tail == nullptr)
	{
		return true;
	}
	return false;
}

unsigned LinkedList::length() const
{
	return size;
}

void LinkedList::print() const
{
	Node* ptr=head;
	for (int i = 0; i < size; ++i)
	{
		cout <<"Value "<<i<<": "<< ptr->getData()<<endl;
		ptr = ptr->getNext();
	}
}

const char* LinkedList::at(int index1) const
{
	if (index1 > size || index1 < 1)
	{
		return "Wrong index";
	}
	Node* ptr = get(index1);
	return ptr->getData();
}

bool LinkedList:: operator==(const LinkedList& other) const
{
	if (size != other.size)
	{
		return false;
	}
	for (int i = 1; i <= size; ++i)
	{
		if((strcmp(other.at(i), at(i))!=0))
		{
			return false;
		}
	}
	return true;
}