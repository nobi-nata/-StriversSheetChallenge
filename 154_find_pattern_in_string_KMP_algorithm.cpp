#include <bits/stdc++.h>
bool findPattern(string p, string s)
{
    int n = p.size();
    int m = s.size();

    for (int i = 0; i <= m - n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (p[j] != s[i + j])
                break;
        }
        if (j == n)
            return true;
    }
    return false;
}

// one-line-code
#include <bits/stdc++.h>
bool findPattern(string p, string s)
{
    return strstr(s.c_str(), p.c_str());
}

//  KMP-Algorithm
