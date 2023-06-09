string kthPermutation(int n, int k)
{
    int fact = 1;
    vector<int> num;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);
    string s = "";
    k = k - 1;
    while (true)
    {
        s = s + to_string(num[k / fact]);
        num.erase(num.begin() + (k / fact));
        if (num.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / num.size();
    }
    return s;
}
