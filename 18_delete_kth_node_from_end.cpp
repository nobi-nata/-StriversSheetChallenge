Node *removeKthNode(Node *head, int K)
{
    Node *d = new Node(0);
    d->next = head;
    Node *slow = d;
    Node *fast = d;
    for (int i = 1; i <= K; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return d->next;
}