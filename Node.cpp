#define _CRT_SECURE_NO_WARNINGS
#include "Node.h"
//#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void Node::setData(const char* data1)
{
	data = new char[strlen(data1) + 1];
	strcpy(data, data1);
}

void Node::setNext(Node* next1)
{
	next = next1;
}

Node::Node(const char* data1, Node* next1)
{
	data = new char[strlen(data1) + 1];
	strcpy(data, data1);
	next = next1;
}

Node::Node(const Node &c)
{
	data = new char[strlen(c.data) + 1];
	strcpy(data, c.data);
	next = c.next;
}

Node::~Node()
{
	if (data) {
		delete data;
	}
}
