
//BRUTE FORCE SOLUTION
//TC - O(N)
//SC - O(1)
int singleNonDuplicate(vector<int> &arr)
{
    int XOR = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR = XOR ^ arr[i];
    }
    return XOR;
}

//OPTIMISED - BINARY-SEARCH
//TC - o(log(n))
//SC - o(1)
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (arr[mid] == arr[mid ^ 1])
        {
            low = low + 1;
        }
        else
        {
            high = high - 1;
        }
    }
    return arr[low];
}

// other optimised approach
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid % 2 == 0)
        {
            if (nums[mid] != nums[mid + 1])
                // Checking whether we are in right half

                high = mid - 1; // Shrinking the right half
            else
                low = mid + 1; // Shrinking the left half
        }
        else
        {

            // Checking whether we are in right half
            if (nums[mid] == nums[mid + 1])
                high = mid - 1; // Shrinking the right half
            else
                low = mid + 1; // Shrinking the left half
        }
    }

    return nums[low];
}