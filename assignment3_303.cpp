#include <iostream>
#include "ExpressionManager.h"
#include "queue.h"

int main() {

	//different checks of the two parts of the assignment 

	ExpressionManager em;
	em.readInfix();
	cout << em.checkIfValid() << endl;
	em.convertToPostfix();
	cout << endl;

	Queue numbers;
	numbers.pushBack(5);

	numbers.pushBack(10);


	cout << "The top of the queue is " << numbers.getTop() << endl;

	numbers.pop();

	cout << "The top of the queue is " << numbers.getTop() << endl;

	cout << "The size of the queue is " << numbers.getSize() << endl;

	cout << "Is the queue empty: " << numbers.isEmpty();

}