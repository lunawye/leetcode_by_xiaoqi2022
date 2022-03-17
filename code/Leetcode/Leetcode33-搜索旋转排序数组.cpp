class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
            if (nums[0] == target)
                return 0;
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] <= nums[right]) //右边有序
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1; //要把target完全限制在两边
                else
                    right = mid - 1;
            }
            else if (nums[left] <= nums[mid]) //左边有序
            {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1; //要把target完全限制在两边
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};