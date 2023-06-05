Node *findIntersection(Node *headA, Node *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    Node *a = headA;
    Node *b = headB;
    while (a != b)
    {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}