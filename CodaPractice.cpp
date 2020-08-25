#include "stdafx.h"
#include <iostream>

using namespace std;


struct Node
{
	int data;
	Node *next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}

};


void printList(Node* head)
{
	Node* temp;
	temp = head;

	while (temp!=NULL)
	{
		cout << temp->data;
		temp = temp->next;
	}
}

void pushLast(Node* head,int x)
{
	Node* temp = new Node(x);

	Node* iterator = head;

	while (iterator->next!=NULL)
	{
		iterator = iterator->next;
	}
	iterator->next = temp;
}


int main()
{
	Node* first = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);

	first->next = second;
	second->next = third;
	
	printList(first);

	pushLast(first, 4);
	cout << endl << "After insert at last : " << endl;
	
	printList(first);
	
    return 0;
}

