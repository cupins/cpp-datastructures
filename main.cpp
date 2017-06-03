///////////////////////////////////////////////////////////////////////
//  Reid Stuberg
//  5/29/2016
///////////////////////////////////////////////////////////////////////
//  This program implements a node and List class which use each other
//  to attain the behavoir of a doubly linked list. This linked list
//  is of a generic type or template type so it can uses any params
//  just like STL. The list also implements the stack and Queue.
///////////////////////////////////////////////////////////////////////
//#include "stdafx.h"

// New class functions
#include "Node.cpp"
#include "List.cpp"
#include "Stack.cpp"
#include "Queue.cpp"


// STL includes
#include <vector>
#include <string>
#include <iostream>


using namespace std;

int main()
{
	cout << "NODE TEST FUNCTIONS" << endl;
	// Node functions display
	Node<int> h = Node<int>(2);
	Node<int> e = Node <int>(34);
	Node<int> p = Node <int>(42);
	h.setData(100);
	h.setNext(&e);
	h.setPrev(&p);
	cout << h.getNext()->getData()  << " " << h.getData() << " " << h.getPrev()->getData() << endl;
//	system("pause");

	// List test
	cout << endl <<"LIST TEST FUNCTIONS" << endl;
	List<char> emp ('X');

	emp.addFirst('R');
	emp.addFirst('d');
	emp.addLast('z');
	emp.addFirst('l');  // gets Removed
	emp.addLast('P');   // gets Removed
	emp.removeFirst();
	emp.removeLast();
	emp.print();

	List<int> mop = List<int>();
	if (mop.isEmpty())
		cout << endl << "is empty works" << endl;
	cout << endl << emp << " size " << emp.size() << endl;

//	system("pause");

	// Queue test
	cout << endl << "QUEUE TEST FUNCTIONS" << endl;

	Queue<string> q;
	q.enqueue("one");  // gets removed
	q.print();
	q.enqueue("two");
	q.enqueue("three");
	q.dequeue();
	cout << endl << q << endl;		// ostream overloaded
//	system("pause");

	// Stack test
	cout << endl << "STACK TEST FUNCTIONS" << endl;

	Stack<double> st;
	st.push(2.001);
	st.push(30.008);
	st.print();
	st.pop();
	cout << endl << st << endl;
//	system("pause");

    return 0;
}

