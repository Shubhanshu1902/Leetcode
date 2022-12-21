#include <bits/stdc++.h>
using namespace std;

// [4,5,6,7,0,1,2]
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                if (nums[l] > target && nums[mid] > nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else if (nums[mid] < target)
            {
                if (nums[mid] < nums[l] && nums[l] <= target)
                    r = mid - 1;

                else
                    l = mid + 1;
            }
        }

        return -1;
    }
};