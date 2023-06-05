bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    if (head == NULL)
        return false;
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
        return false;
    return true;
}