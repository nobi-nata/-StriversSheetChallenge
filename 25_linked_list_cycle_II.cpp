Node *firstNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    if (head == NULL)
        return NULL;
    do
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    } while (fast != NULL && (fast != slow));
    if (fast == NULL)
        return NULL;
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}