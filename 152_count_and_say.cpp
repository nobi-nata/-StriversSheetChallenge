#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
    string num = "1";
    while (n > 1)
    {
        string s = "";
        for (int i = 0; i < num.size(); i++)
        {
            int cnt = 0, j;
            for (j = i; j < num.size(); j++)
            {
                if (num[i] == num[j])
                    cnt++;
                else
                {
                    s += to_string(cnt);
                    s += num[i];
                    i = j - 1;
                    break;
                }
            }
            if (j == num.size())
            {
                s += to_string(cnt);
                s += num[i];
                i = j - 1;
            }
        }
        num = s;
        n--;
    }
    return num;
}