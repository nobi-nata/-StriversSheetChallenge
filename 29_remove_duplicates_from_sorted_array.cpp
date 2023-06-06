int removeDuplicates(vector<int> &arr, int n)
{
    int i = 0;
    for (auto j : arr)
    {
        if (arr[i] != j)
        {
            arr[++i] = j;
        }
    }
    return i + 1;
}