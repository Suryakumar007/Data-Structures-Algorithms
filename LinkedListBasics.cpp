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
		cout << temp->data<< " ->";
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

void rotateList(Node *head, int k)
{
	Node *p;
	Node *q;
	Node *r;

	p = head;
	q = head;
	while (k>1)
	{
		p = p->next;
		k--;
	}

	while (q->next!=NULL)
	{
		q = q->next;
	}

	q->next = head;
	head = p->next;
	p->next = NULL;

	printList(head);
}

bool detectLoop(Node *head)
{
	Node *p;
	Node *q;

	p = head; q = head;

	while (p && q && q->next)
	{
		p = p->next;
		q = q->next->next;

		if (p == q)
			return true;
	}
	return false;

}

void detectRemoveLoop(Node *head)
{
	Node *p=head;
	Node *q=head;

	while (p && q && q->next)
	{
		p = p->next;
		q = q->next->next;

		if (p == q)
			break;
	}

	if (p == q)
	{
		q = head;
		while ( p->next != q->next)
		{
			p = p->next;
			q = q->next;
		}
		p->next = NULL;
	}
}

Node* mergeTwoSortedList(Node *p, Node *q)
{
	Node *s = NULL;
	Node *newHead = NULL;

	if (p && q)
	{
		if (p->data < q->data)
		{
			s = p;
			p = s->next;
		}
		else
		{
			s = q;
			q = s->next;
		}
		newHead = s;
	}

	while (p && q)
	{
		if (p->data < q->data)
		{
			s->next = p;
			s = p;
			p = s->next;
		}
		else
		{
			s->next = q;
			s = q;
			q = s->next;
		}
	}
	if (p == NULL)
	{
		s->next = q;
	}
	else
	{
		s->next = p;
	}

	return newHead;
}

int nthNodeFromEnd(Node *head,int n)
{
	Node *p=head;
	Node *q=head;
	int counter = n,nodecounter=0;

	while (counter >1 && p->next)
	{
		p = p->next;
		counter--;
		nodecounter++;
	}

	

	while (p->next!=NULL)
	{
		p = p->next;
		q = q->next;
		nodecounter++;
	}

	if (n-1 > nodecounter)
	{
		return -1;
	}

	return q->data;

}


int main()
{
	Node* p = new Node(1);

	pushLast(p, 2);
	pushLast(p, 3);
	pushLast(p, 4);
	pushLast(p, 5);

	int n = 5;

	
	//detectRemoveLoop(first);

	int check = nthNodeFromEnd(p, n);
	cout << endl << "After Sorting : " << check;
	//printList(check);

	//cout << a;
	
    return 0;
}

