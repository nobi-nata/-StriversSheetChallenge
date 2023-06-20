vector<int> stringMatch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    int i = -1;
    vector<int> ans;
    while (i < n)
    {
        int j = 0;
        int flag = true;
        while (i < n && j < m && text[i] == pattern[j])
        {
            i++;
            j++;
            flag = false;
        }
        if (j == m)
            ans.push_back(i - m + 1);
        if (flag)
            i++;
        else
            i = i - j + 1;
    }
    return ans;
}
