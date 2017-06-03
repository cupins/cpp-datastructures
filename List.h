

//#pragma once
#ifndef LIST_H_
#define LIST_H_
// dependencies
#include "Node.h"

#include <iostream>
#include <string>

using namespace std;

template <class T>
class List {
private:

	Node<T> *head;
	Node<T> *tail;
public:

	List();

	List(T data);

	virtual ~List();

	void addLast(T);


	void addFirst(T);

	T removeLast();

	T removeFirst();

	bool isEmpty() const;

	int size() const;


	virtual void print() const;


	friend ostream &operator<<(ostream& out, const List& x) {
		Node<T> *temp = x.head;
		while (temp != NULL) {
			out << temp->getData() << " " ;
			temp = temp->getNext();
		}
		return out;
	}
	
};
#endif