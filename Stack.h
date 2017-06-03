

//#pragma once

// dependencies
#include "List.h"
#include <iostream>

using namespace std;


template <class T>
class Stack : public List<T> {
public:
	void push(T name);
	T pop();

	virtual void print() const;
	friend ostream &operator<<(ostream& out, const Stack& x){
		const List<T> &temp = x;
		out << temp;
		return out;
	}
};