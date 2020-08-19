#include "Stack.h"

Stack::Stack() {
	list = new LinkedList();
}

Stack::~Stack()
{
	delete list; 
}

const char* Stack::top() const
{
	return list->at(list->length());
}

void  Stack::pop()
{
	list->remove(list->length());
}

void Stack::push(const char* data)
{
	list->append(data);
}

bool Stack::isEmpty() const
{
	return list->isEmpty();
}

void Stack::print() const
{
	int size = list->length();
	for (int i=size; i > 0; --i)
	{
		cout << list->at(i) << endl;
	}
}
