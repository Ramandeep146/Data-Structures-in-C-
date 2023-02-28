/**
* Access to element: O(n)
* Insertion: O(n)
* Deletion: O(n)
**/


/**
*						Array							LinkedList
* Cost of accessing				O(1)							O(n)
  an element
* 
* Memory Usage					Fixed Size						No Unused memory
						(Used + Unused)						Extra memory for pointer variables
						-> One large block					-> If the data part of the list is large
						of memory may not 					Then the linked list might consume less memory
						be available						as compared to arraylist.
													-> No contiguous block of memory, so memory might
													be available
* 
* Inserting/Deleting 
  Elements
		Beginning			O(n)							O(1)
		
		End				O(1) - If array not full				O(n)
						O(n) - If array is full
		
		ith Position			O(n)							O(n)							

* 
**/

#include <stdio.h>

class LinkedList {

public:

	int size;

	struct Node {
		int data;
		struct Node *next; // we do not need to use struct in c++ but for c we use it
	};

	struct Node *head; // Global Variable

public:
	LinkedList() {
		head = NULL;
		size = 0;
	}

public:
	int get(int n) {
		Node* temp = head;
		for (int i = 0; i < n; i++) {
			temp = temp->next;
		}
		return temp->data;
	}

	void insertFront(int x) {

		Node* temp = new Node();

		(*temp).data = x;
		(*temp).next = head;

		head = temp;
		size++;
	}

public:
	void insert(int x, int n) {
		
		
		if (head == NULL || n==0) {
			insertFront(x);
			return;
		}

		if (n>size-1) {
			printf("Out of bounds for inserting element %d at index %d\n", x, n);
			return;
		}

		Node* temp = new Node();
		temp->data = x;

		Node* temp2 = head;

		for (int i = 0; i < n-1; i++) {
			temp2 = temp2->next;
		}

		temp->next = temp2->next;
		temp2->next = temp;


		size++;
	}

public:
	void insertLast(int x) {

		if (head == NULL) {
			insertFront(x);
			return;
		}

		Node* temp = new Node();

		(*temp).data = x;
		(*temp).next = NULL;

		Node* temp2 = head;

		while (temp2->next != NULL) {
			temp2 = temp2->next;
		}
		temp2->next = temp;

		size++;
	}

public:
	void remove(int n) {

		if (head == NULL) {
			printf("Empty Linked List, cannot delete any item.\n");
			return;
		}

		Node* temp = head;

		if (n==0) {
			head = temp->next;
			delete(temp); /** IMPORTANT TO CLEAR THE VARIABLE FROM THE MEMORY**/
			size--;
			return;
		}

		if (n>size-1) {
			printf("Out of bounds for deleting element at index %d\n", n);
			return;
		}

		for (int i = 0; i < n - 1; i++) {
			temp = temp->next;
		}

		Node* temp2 = temp->next;

		temp->next = temp2->next;
		delete(temp2); /** IMPORTANT TO CLEAR THE VARIABLE FROM THE MEMORY**/
		size--;

	}

public:
	void reverse() {

		if (head == NULL) {
			printf("Empty List! Cannot Reverse\n");
			return;
		}

		Node* temp = head;
		Node* prevNode = NULL;
		Node* nextNode;

		while (temp!=NULL) {
			nextNode = temp->next;
			temp->next = prevNode;
			prevNode = temp;
			temp = nextNode;	
		}
		//temp = prevNode;
		head = prevNode;
	}

	void recurseReverse() {
		reverseUsingRecursion(head);
	}

public:
	void print() {
		//Node* temp = new Node(); // You can also use malloc
		Node* temp = head;
		printf("The values are:");
		while (temp != NULL) {
			printf(" %d", (*temp).data);
			temp = (*temp).next;
		}
		printf("\n");
	}

	void printReverse() {
		printf("LinkedList in reverse order is: ");
		recurseBack(head);
		printf("\n");
	}

private:
	void recurseBack(Node* temp) {
		if (temp == NULL) {
			return;
		}
		recurseBack(temp->next);
		printf(" %d", temp->data);
	}

	Node* reverseUsingRecursion(Node* temp) { //////////////////IMPORTANT**********************************************
		if (temp->next == NULL) {
			head = temp;
			return NULL;
		}
		reverseUsingRecursion(temp->next);
		Node* a = temp->next;
		a->next = temp;
		temp->next = NULL;
	}
};



int main() {

	LinkedList myList;

	myList.insertFront(20);

	myList.print();

	myList.insertLast(10);

	myList.print();

	myList.insert(22, 1);

	myList.print();

	myList.insert(2,2);

	myList.print();

	myList.printReverse();

	myList.recurseReverse();
	myList.print();

	printf("Element is %d", myList.get(0));


}
