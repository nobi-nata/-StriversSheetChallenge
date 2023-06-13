//BRUTE FORCE
//TC - O(N1+N2)
//SC - O(N1+N2)
float median(int nums1[], int nums2[], int m, int n)
{
    int finalArray[n + m];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            finalArray[k++] = nums1[i++];
        }
        else
        {
            finalArray[k++] = nums2[j++];
        }
    }
    if (i < m)
    {
        while (i < m)
            finalArray[k++] = nums1[i++];
    }
    if (j < n)
    {
        while (j < n)
            finalArray[k++] = nums2[j++];
    }
    n = n + m;
    if (n % 2 == 1)
        return finalArray[((n + 1) / 2) - 1];
    else
        return ((float)finalArray[(n / 2) - 1] + (float)finalArray[(n / 2)]) / 2;
}

//BRUTE - OPTIMISED
//TC - O(N1+N2)
//SC - O(1)

double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int p = 0;
    int q = 0;
    int cnt = -1;
    int key;
    if ((n1 + n2) % 2)
        key = (n1 + n2) / 2;
    else
        key = (n1 + n2) / 2 - 1;
    double ele;
    double ans = 0;

    while (p < n1 && q < n2)
    {

        if (a[p] < b[q])
        {
            cnt++;
            ele = a[p];
            p++;
        }
        else
        {
            cnt++;
            ele = b[q];
            q++;
        }
        if (cnt == key)
        {
            ans += ele;
            if ((n1 + n2) % 2 == 1)
                return ele;
        }
        if (cnt - 1 == key)
        {
            ans += ele;
            return double(ans / 2);
        }
    }
    while (p < n1)
    {
        cnt++;
        ele = a[p];
        p++;
        if (cnt == key)
        {
            ans = ele;
            if ((n1 + n2) % 2 == 1)
                return ele;
        }
        if (cnt - 1 == key)
        {
            ans += ele;
            return double(ans / 2);
        }
    }
    while (q < n2)
    {
        cnt++;
        ele = b[q];
        q++;
        if (cnt == key)
        {
            ans = ele;
            if ((n1 + n2) % 2 == 1)
                return ele;
        }
        if (cnt - 1 == key)
        {
            ans += ele;
            return double(ans / 2);
        }
    }
}

// OPTIMAL
//TC - O(log(min(n1,n2)))
//SC - O(1)
double median(vector<int> &a, vector<int> &b)
{
    if (a.size() > b.size())
        return median(b, a);

    int n = a.size();
    int m = b.size();

    int low = 0;
    int high = n;

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (n + m + 1) / 2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : a[cut1];
        int r2 = cut2 == m ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n + m) % 2 == 1)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }

    return 0.0;
}