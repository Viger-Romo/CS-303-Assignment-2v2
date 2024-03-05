#include <iostream>
#include <cstddef>

using namespace std;

template<typename Item_Type> //Is used so they can put in any data type they want when creating a SingleLinkedList
class SingleLinkedList {
private:

	struct Node { //Node struct to hold data and pointer to the next node
		Item_Type data; //Will store the data
		Node* next; //Pointer to next node
		Node(const Item_Type& item) : data(item), next(nullptr) {} //Constructor used to initialize node
	};

	Node* head; //Pointer to first node in list
	Node* tail; //Pointer to last node in list
	size_t num_items; //Number of items in the list

public:

	SingleLinkedList() :head(nullptr), tail(nullptr), num_items(0) {}; //Constructor used to create empty list

	~SingleLinkedList() { //Destructor used to deallocate memeory of the nodes used in the list
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	};

	bool empty() const;//Checks if the list is empty
	Item_Type& front() const; //Returns the first item in the list
	Item_Type& back() const; //Returns the lat item in the list

	void push_front(const Item_Type& item); //Will add an item to the beginning of the list  
	void push_back(const Item_Type& item); //Will add an item to the end of the list

	void pop_front();//Removes item at the beginning of the list
	void pop_back();//Removes item at the end of the list

	void insert(size_t index, const Item_Type& item); //Inserts an item at a specific index of the list, if index is greater than the list it will add to the end
	bool remove(size_t index);//Removes an item at index provided and returns true if it was able to or false if not
	size_t find(const Item_Type& item) const; //Finds the index at the first occurence of an item in the list

};

//Note: Was encoutering errors when trying to run the following code in a .cpp file, that why these functions are here in the .h file instead of .cpp

template<typename Item_Type>
bool SingleLinkedList<Item_Type>::empty() const {
	return head == nullptr; //Returns true or flase if the list is empty
}

template<typename Item_Type>
Item_Type& SingleLinkedList<Item_Type>::front() const {
	if (!empty()) //If the list is not empty
		return head->data; //Returns the data at the front of the list
}
template<typename Item_Type>
Item_Type& SingleLinkedList<Item_Type>::back() const {
	if (!empty()) { //If the list is empty
		return tail->data; //Returns the data at the end of the lsit
	}
}

template<typename Item_Type>
void SingleLinkedList<Item_Type> ::push_front(const Item_Type& item) {
	Node* newNode = new Node(item);
	if (empty()) {
		tail = newNode; //If list is empty, it will update teh tail to point to the new node
	}
	newNode->next = head; //Updates next pointer of the new node to point to current head
	head = newNode; //Update head to point to new node
	num_items++; //Adds to number of items in list
}

template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_back(const Item_Type& item) {
	Node* newNode = new Node(item);
	if (empty()) {
		head = newNode; //If list is empty, updates head to point to the new node
	}
	else {
		tail->next = newNode; //Updates next pointer of current tail to point to new node
	}
	tail = newNode; //Updates the tail to point to new node
	num_items++; //Adds to number of items in list
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::pop_front() {

	if (!empty()) { //Checks if empty or not
		Node* temp = head; //Stores the pointer to current head
		head = head->next; //Update head to point to next node
		delete temp; //Deallocates memory of the old head
		num_items--; //Subtracts number of items in list
		if (empty()) {
			tail = nullptr; //If the list is empty, then the tail will be a nullptr
		}
	}
}
template<typename Item_Type>
void SingleLinkedList<Item_Type>::pop_back() {

	if (!empty()) {
		if (head == tail) {
			delete head; //If the list has only one item, it will delete it
			tail = nullptr; //Tail will be nullptr
			head = tail; //Head will aslo be nullptr
		}
		else {
			Node* temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			delete tail; //Delete the current tail
			tail = temp; //Tail will point to the previous node
			tail->next = nullptr;//Set next pointer of tail to nullptr
		}
		num_items--; //Subtracts the number of items in list
	}
}
template<typename Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
	if (index == 0) {
		push_front(item); //If index is 0, it will insert item to the front of the list
		return; //Exits function.
	}
	if (index >= num_items) {
		push_back(item); //If index is greater than then the number of items in the list, it will insert at the end of the list
		return;
	}

	Node* currentElement = head; //Node that will be used for the current element 
	for (size_t i = 0; i < index - 1; i++) { 
		currentElement = currentElement->next; //Goes through the list to find node at the very end
	}
	Node* newNode = new Node(item); //New Node of the item
	newNode->next = currentElement->next; //Updatethe next pointer of the new node
	currentElement->next = newNode; //Update the previous node
	num_items++; //Adds to the number of elements in the list
}

template<typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {
	if (index >= num_items) {
		return false; //If the index is out of range, it will return false
	}
	if (index == 0) {
		pop_front(); //Removes the item at the front of the list if index is 0
		return true; //Returns true to show item has been removed
	}
	Node* currentElement = head; //Node that will be used for the current element 
	for (size_t i = 0; i < index - 1; i++) {
		currentElement = currentElement->next; //Goes through the list to find node at the very end
	}
	Node* temp = currentElement->next; //Pointer to next node that will be removed
	currentElement->next = temp->next; //Updates teh previous pointer to previous node
	delete temp; //Dellacoates memeory of node that is removed
	num_items--;//Subtracts number of items in the list
	if (index == num_items) {
		tail = currentElement; //Updates tail to point to previous node
	}
	return true; //Returns ture to show item has been removed
}

template<typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) const { 
	Node* currentElement = head; //Start from the head of the list
	size_t index = 0; //Starting index
	while (currentElement != nullptr) {
		if (currentElement->data == item) { //If the data of the current node matches the item provided, it will return the index
			return index; //Returns index
		}
		currentElement = currentElement->next; //Goes to next node
		index++; //Inrement index
	}
	return num_items;//Returns the size of the list if it could not find the item.
}