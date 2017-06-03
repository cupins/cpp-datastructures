
//#include "stdafx.h"
#include "List.h"

///////////////////////////////////////////////////////////////////////
// Constructors/Destructors

//! Default Constructor
template <class T>
List<T>::List() {
	this->head = NULL;
	this->tail = NULL;

}
///////////////////////////////////////////////////////////////////////
//!  Parameters: a generic variable x which becomes the data of a node
//
//!  Overloaded constructor for one/beginning node
///////////////////////////////////////////////////////////////////////
template <class T>
List<T>::List(T data) {
	Node<T> *newNode = new Node<T>(data);
	this->head = newNode;
	this->tail = newNode;
}

///////////////////////////////////////////////////////////////////////
//!  Parameters: NONE
//
//!  Virtual destructor for the queue and stack class
///////////////////////////////////////////////////////////////////////
template <class T>
List<T>::~List() {
	Node<T> *temp = head;
	while (temp != NULL) {
		temp = temp->getNext();
		delete head;
		head = temp;
	}
	head = NULL;
	temp = head;
	// are there dangling pointers inside nodes?
}
// End Constructors/Destructors
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Modifiers

///////////////////////////////////////////////////////////////////////
//!  Parameters: a generic variable x which becomes the data of a node
//
//!  Adds an element to the end of a list.
///////////////////////////////////////////////////////////////////////
template <class T>
void List<T>::addLast(T x) {
	Node<T> *newNode = new Node<T>(x);
	if (this->head == NULL) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		Node<T> *n = newNode;
		this->tail->setNext(n);
		n->setPrev(this->tail);
		this->tail = n;
	}
}
///////////////////////////////////////////////////////////////////////
//!  Parameters: a generic variable x which becomes the data of a node
//
//!  Adds an element to the beginning of a list.
///////////////////////////////////////////////////////////////////////
template <class T>
void List<T>::addFirst(T x) {
	Node<T> *n = new Node<T>(x);
	if (this->head == NULL) {
		this->head = n;
		this->tail = n;
	}
	else {
		this->head->setPrev(n);
		n->setNext(this->head);
		this->head = n;
	}
}

///////////////////////////////////////////////////////////////////////
//!  Parameters: a generic variable x which becomes the data of a node
//
//!  Adds an element to the beginning of a list.
///////////////////////////////////////////////////////////////////////
template <class T>
T List<T>::removeLast() {
	// if it's already empty do nothing
	if (this->head == NULL)
		return NULL;
	T data = this->tail->getData();
	Node<T> *temp = this->tail;
	this->tail = this->tail->getPrev();
	this->tail->setNext(NULL);

	temp->setPrev(NULL);
	temp->setNext(NULL);
	delete temp;
	return data;
}

///////////////////////////////////////////////////////////////////////
//!  Parameters: a generic variable x which becomes the data of a node
//
//!  Adds an element to the beginning of a list.
///////////////////////////////////////////////////////////////////////
template <class T>
T List<T>::removeFirst() {
	// if it's already empty do nothing
	if (this->head == NULL)
		return NULL;

	T data = this->head->getData();
	Node<T> *temp = this->head;
	this->head = this->head->getNext();
	this->head->setPrev(NULL);

	temp->setPrev(NULL);
	temp->setNext(NULL);
	delete temp;
	return data;
}

// End Modifiers
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Capacity functions

///////////////////////////////////////////////////////////////////////
//!  Parameters: NONE
//
//!  returns true if there is a size else false
///////////////////////////////////////////////////////////////////////
template <class T>
bool List<T>::isEmpty() const {
	return this->size() == 0;
}



///////////////////////////////////////////////////////////////////////
//!  Parameters: NONE
//
//!	 returns the size of the list
///////////////////////////////////////////////////////////////////////
template <class T>
int List<T>::size() const {
	if (this->head == NULL)
		return 0;
	Node<T> *temp = head;
	int size = 1;
	while (temp->getNext() != NULL) {
		temp = temp->getNext();
		size++;
	}
	return size;
}
// End Capacity 
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Print Functions

///////////////////////////////////////////////////////////////////////
//!  Parameters: NONE
//
//!	 Prints the list in order
///////////////////////////////////////////////////////////////////////
template <class T>
void List<T>::print() const {
	cout << endl;
	Node<T> *temp = this->head;


	while (temp != NULL) {
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
}

// End Print Functions
///////////////////////////////////////////////////////////////////////
