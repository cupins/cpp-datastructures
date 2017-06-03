//#pragma once
#ifndef NODE_H_
#define NODE_H_
using namespace std;
#include <string>

/// list will contain dependencies for node
template <class T>
class Node {
private:
	T data;
	Node *prev;
	Node *next;
public:
	
	Node(T data);

	T getData() const;
	void setData(const T &data);
	Node *getNext();
	Node *getPrev();
	void setNext(Node *n);
	void setPrev(Node *p);
};


#endif /* NODE_H_ */
