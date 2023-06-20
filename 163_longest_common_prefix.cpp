string longestCommonPrefix(vector<string> &arr, int n)
{
    string a = arr[0];
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (a[j] == arr[i][j])
        {
            j++;
        }
        a = a.substr(0, j);
    }
    return a;
}
