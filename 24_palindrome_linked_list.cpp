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

bool isPalindrome(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverseLinkedList(slow->next);
    slow = slow->next;

    while (slow != NULL)
    {
        if (head->data != slow->data)
        {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}