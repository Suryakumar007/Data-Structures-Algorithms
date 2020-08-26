bool isPalindrome(Node *head)
{
	Node *p = head;
	Node *q = head;
	stack <int> s;

	while (p)
	{
		s.push(p->data);
		p = p->next;
	}

	while (q)
	{
		int temp = s.top();
		s.pop();

		if (temp != q->data)
		{
			return false;
		}
		q = q->next;
	}
	
	return true;
	
}

int intersectionPoint(Node * head1, Node * head2)
{
	Node *p;
	Node *q;

	p = head1;
	q = head2;

	int count1=0, count2=0;
	while (head1)
	{
		head1 = head1->next;
		count1++;
	}

	while (head2)
	{
		head2 = head2->next;
		count2++;
	}

	int diff = abs(count1 - count2);

	if (count1 > count2)
	{
		while (diff)
		{
			p = p->next;
			diff--;
		}
	}
	else
	{
		while (diff)
		{
			q = q->next;
			diff--;
		}
	}

	while (p && q)
	{
		if (p == q)
			return p->data;

		p = p->next;
		q = q->next;
	}

	return -1;
}
