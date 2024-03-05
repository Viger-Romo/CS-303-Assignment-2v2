#include "Stack.h"
#include "SingleLinkedList.h"

Stack::Stack(){} //Constructor of the stack class

bool Stack::isEmpty() const {
	return data.empty(); //Returns true if the stack is empty
}
void Stack::pushData(int num) { 
	data.push_back(num); //Adds the integer provided to the top of the stack
}

void Stack::popData() {
	if (!isEmpty()) { //Checks if the stack is empty or not
		data.pop_back(); //Removes element from the top of the stack
	}
}

int Stack::findTop() const {
	if (!isEmpty()) { //Checks if the stack is empty or not
		return data.back(); //Return the item at the top of the stack
	}
	return -1; //Exits if not
}

double Stack::average() const {
	if (isEmpty()) { //Checks if the stack is empty
		return 0.0; //Returns zero if empty
	}
	double sum = 0; //Double to get the sum
	for (int value : data) { //Goes through the stack
		sum += value; //Adds the values of the stack to sum
	}
	return sum / data.size(); //Returns the average of the stack
}