#include "Queue.h"

Queue::Queue()
{
	list = new LinkedList();
}

Queue::~Queue()
{
	delete list;
}

void Queue::enqueue(const char* value)
{
	list->append(value);
}

void Queue::dequeue()
{
	list->remove(1);
}

const char* Queue::front() const
{
	return list->at(1);
}

bool Queue::isEmpty() const
{
	return list->isEmpty();
}

void Queue::print() const
{
	int size = list->length();
	for (int i = 1; i <=size; ++i)
	{
		cout << list->at(i) << endl;
	}
}
