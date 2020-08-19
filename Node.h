#pragma once

class Node {
private:
	char* data;
	Node* next;
public:
	void setData(const char* data1);
	char* getData() { return data; }
	void setNext(Node* next1);
	Node* getNext() { return next; }
	Node() { data = nullptr, next = nullptr; }// default ctor
	Node(const char* data1, Node* next1);// ctor
	Node(const Node &c);//copy ctor
	~Node();//dtor
};
