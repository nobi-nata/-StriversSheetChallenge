//BRUTE FORCE
//TC - O(N^2)
string reverseString(string &str)
{
    str = str + ' ';
    int n = str.size();
    string ans = "";

    for (int i = n - 1; i >= 0; i--)
    {
        while (str[i] == ' ')
            i--;
        int j = i;
        while (str[j] != ' ' && j >= 0)
        {
            j--;
        }
        i = j + 1;
        while (str[i] != ' ')
        {
            ans = ans + str[i];
            i++;
        }
        ans = ans + ' ';
        i = j + 1;
    }
    return ans.substr(0, n - 1);
}

//BRUTE - USING STACK
//TC - O(n)
//SC - o(N)
#include <bits/stdc++.h>

string reverseString(string &str)
{
    str = str + " ";
    stack<string> st;

    string s = "";
    int flag = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            flag = 0;
            s += str[i];
        }
        else if (!flag)
        {
            st.push(s);
            s = "";
            flag = 1;
        }
    }
    string ans = "";
    while (st.size() != 1)
    {
        ans += st.top() + " ";
        st.pop();
    }
    ans += st.top();
    return ans;
}

//OPTIMAL
//TC - O(N)
//SC - O(1)
#include <bits/stdc++.h>

string reverseString(string &str)
{
    int left = 0;
    int right = str.length();

    string temp = "";
    string ans = "";
    int flag = 0;
    while (left < right)
    {
        char ch = str[left];
        if (ch != ' ')
        {
            temp += ch;
            flag = 0;
        }
        else if (!flag)
        {
            if (ans != "")
                ans = temp + " " + ans;
            else
                ans = temp;
            temp = "";
            flag = 1;
        }
        left++;
    }

    if (temp != "")
    {
        if (ans != "")
            ans = temp + " " + ans;
        else
            ans = temp;
    }
    return ans;
}
