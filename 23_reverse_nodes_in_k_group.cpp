
Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    stack<int> ans;
    Node *temp = head;
    Node *p = head;
    int cnt = -1;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == n)
            return head;
        for (int i = 0; i < b[cnt]; i++)
        {
            if (temp == NULL)
                break;
            ans.push(temp->data);
            temp = temp->next;
        }
        temp = p;
        while (!ans.empty())
        {
            temp->data = ans.top();
            ans.pop();
            temp = temp->next;
        }
        p = temp;
    }
    return head;
}