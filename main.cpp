#include "SingleLinkedList.h"
#include "Stack.h"

int main() {


	SingleLinkedList<int> list; //Create single linked list
	
	list.push_front(20); //Pushes 20 to the front of the linked list
	cout << "Front of the list: " << list.front() << endl; //Outputs the front of list

	//Checks if the list is emtpy
	if (list.empty()) {
		cout << "The list is empty" << endl; 
	}
	else {
		cout << "The list is not empty" << endl;
	}

	//Adds items to the front of the list
	list.push_front(30);
	list.push_front(2003);
	list.push_front(15);
	list.push_front(87);
	//Adds items to the back of the list
	list.push_back(38);
	list.push_back(95);
	list.push_back(22);


	cout << "The front of the list: " << list.front() << endl;
	cout << "The back of the list: " << list.back() << endl;
	
	list.pop_front(); //Removes item at the front of the list
	list.pop_back(); //Remvoes item at the back of the list
	

	cout << "The front of the list: " << list.front() << endl;
	cout << "The back of the list: " << list.back() << endl;

	//Inserts at and index of the list
	list.insert(3, 13);
	list.insert(4, 12);

	list.insert(50, 1); //Will add to the end of the list

	cout << "The back of the list is " << list.back() << endl;

	//Will remove item at a given index
	if (list.remove(3)) {
		cout << "There was a succesful removal of an item at index 3." << endl;
	}
	else {
		cout << "There is no item at this index" << endl;
	}
	if (list.remove(97)) {
		cout << "There was a succesful removal of an item at index 97." << endl;
	}
	else {
		cout << "There is no item at this index" << endl;
	}


	cout << "The index of 38 is " << list.find(38) << endl;
	cout << "The size of the list is : " << list.find(900) << endl;

	//Goes through and prints out the items in the linked list
	cout << "The items in the list are ";
	for (int i = 0; i < 8; i++) {
		cout << list.front() << " ";
		list.pop_front(); //Gets rid of item at the front of the list
	}
	cout << endl;

	//Checks if the list is empty
	if (list.empty()) {
		cout << "The list is empty" << endl;
	}



	Stack stack; //Creates stack
	if (stack.isEmpty()) { //Checks if the list is empty
		cout << "\nThe stack is empty!" << endl;
	}
	stack.pushData(23); //Pushes data onto the stack
	if (stack.isEmpty()) { //Checks if the stack is empty
		cout << "The stack is empty!" << endl;
	}
	else {
		cout << "There is Data in the stack" << endl;
	}
	
	//Removes item at the front of the list
	stack.popData();
	if (stack.isEmpty()) { //Checks if the list is empty
		cout << "The stack is empty!" << endl;
	}

	//Adds items to the stack
	stack.pushData(50);
	stack.pushData(15);
	stack.pushData(23);
	stack.pushData(24);
	stack.pushData(87);

	cout << "The top value is " << stack.findTop() << endl;
	cout << "The average is " << stack.average() << endl;
	
	stack.popData(); //Removes item at the top of the stack

	cout << "The top value after popping is " << stack.findTop() << endl;
}