LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *p = head;
    LinkedListNode<int> *q = NULL;
    LinkedListNode<int> *r = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    head = q;
    return head;
}