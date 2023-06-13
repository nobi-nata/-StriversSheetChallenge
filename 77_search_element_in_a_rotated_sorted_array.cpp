//BRUTE FORCE
//TC - O(N)
//SC - O(1)
int search(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

//OPTIMISED - BINARY SEARCH
//TC - O(LOG(N))
//SC - O(1)
int search(int *arr, int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == key)
            return mid;
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] <= key && key <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[high] >= key && key >= arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}