class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        if (nums[left] > target)
            return 0;
        if (nums[right] < target)
            return right + 1;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left++;
            else
                right--;
        }
        return left;
    }
};