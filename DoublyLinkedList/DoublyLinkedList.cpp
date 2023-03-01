#include <stdio.h>

template <class T>
class DoublyLinkedList {

public: 
	int size;
	
	struct Node
	{
		Node* prev = NULL;
		T data = NULL;
		Node* next = NULL;
	};

	Node* head;
	Node* tail;

	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	T get(int n) {
		Node* temp;
		if (n < size/2) {
			temp = head;
			for (int i = 0; i < n; i++) {
				temp = temp->next;
			}
		}
		else {
			temp = tail;
			for (int i = 0; i < size-1-n; i++) {
				temp = temp->prev;
			}
		}

		return temp->data;
	}

	void insertFront(T data) {
		
		Node* node = new Node();
		node->prev = NULL;
		node->data = data;
		if (head == NULL) {
			node->next = NULL;
			head = node;
			tail = head;
			size++;
			return;
		}

		head->prev = node;
		node->next = head;
		head = node;
		size++;

	}

	void insert(T data, int n) {
		
		if (head == NULL || n==0) {
			insertFront(data);
			return;
		}
		if (n==size) {
			insertLast(data);
			return;
		}
		if (n>size-1) {
			printf("Index Out of Bounds!\n");
			return;
		}

		Node* temp = head;

		for (int i = 0; i < n - 1; i++) {
			temp = temp->next;
		}

		Node* node = new Node();
		node->data = data;
		node->prev = temp;
		node->next = temp->next;

		(temp->next)->prev = node;
		temp->next = node;

		size++;
	}

	void insertLast(T data) {
		if (head == NULL) {
			insertFront(data);
			return;
		}

		Node* node = new Node();
		node->data = data;
		node->prev = tail;
		node->next = NULL;

		tail->next = node;
		tail = node;

		size++;
	}

	void remove(int n) {
		if (n>size-1) {
			printf("Index out of bounds!\n");
			return;
		}
		Node* temp = head;
		for (int i = 0; i < n; i++) {
			temp = temp->next;
		}
		if (temp->prev == NULL) {
			head = temp->next;
			head->prev = NULL;
		}
		else if (temp->next == NULL) {
			tail = tail->prev;
			tail->next = NULL;
		}
		else {
			(temp->next)->prev = temp->prev;
			(temp->prev)->next = temp->next;
		}
		delete(temp);
		size--;
	}

	void print() {
		
		Node* temp = head;
		printf("The elements are:");
		while (temp != NULL) {
			printf(" %d", temp->data);
			temp = temp->next;
		}

		printf("\n");

		temp = tail;
		printf("The elements are:");
		while (temp != NULL) {
			printf(" %d", temp->data);
			temp = temp->prev;
		}
		printf("\n");
	}

};


int main() {

	DoublyLinkedList<int> myList;

	myList.insertLast(7);
	myList.insertLast(8);
	myList.insertLast(10);

	myList.insertFront(3);
	myList.insertFront(2);
	myList.insertFront(1);

	myList.insert(5, 6);

	myList.print();

	//myList.remove(4);
	//myList.print();

	printf("\n\n%d\n\n", myList.get(7));

}