#include <bits/stdc++.h>
int atoi(string str)
{
    int num = 0;
    int n = str.size();
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '-')
        {
            flag = 1;
        }
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
        {
            int e = str[i] - '0';
            num = num * 10 + e;
        }
    }
    if (flag)
        return -1 * num;
    return num;
}