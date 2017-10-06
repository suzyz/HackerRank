/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
   	Node *p = head,*q;
   	if (head == NULL)
   		return false;

   	q = p -> next;
   	while (q != NULL && q->next != NULL)
   	{
   		if (p==q)
   			return true;
   		p = p->next;
   		q = q->next->next;
   	}
   	return false;
}

