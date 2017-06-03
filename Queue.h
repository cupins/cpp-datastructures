//#pragma once

#include <iostream>
#include "List.h"

using namespace std;


template <class T>
class Queue: public List<T> {
public:

	void enqueue(const T &);
	T dequeue();
	virtual void print() const;
	friend ostream& operator<<(ostream& out, const Queue<T>& x){
		const List<T> &temp = x;
		out << temp;
		return out;
	}
};