#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
	vector<int> data; //Used be used to store elements of the stack
public:
	Stack(); //Constructor to initialize the emepty stack
	bool isEmpty() const; //Checks if the stack is empty
	void pushData(int num); //Pushes an integer onto the stack
	void popData(); //Removes an element from the top of the stack
	int findTop() const; //Returns the top of the stack
	double average() const; //Calculates the average of the integers in the stack

};