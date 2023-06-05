Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    Node<int> *p = first;
    Node<int> *q = second;
    Node<int> *r = new Node<int>(0);
    Node<int> *z = r;
    while (p != NULL && q != NULL)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = r->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        r->next = p;
        p = p->next;
        r = r->next;
    }
    while (q != NULL)
    {
        r->next = q;
        q = q->next;
        r = r->next;
    }
    r->next = NULL;
    return z->next;
}