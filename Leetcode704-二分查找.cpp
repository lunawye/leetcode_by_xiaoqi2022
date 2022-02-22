class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        else if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[(left + right) / 2] == target)
                return (left + right) / 2;
            else if (nums[(left + right) / 2] < target)
                left++;
            else if (nums[(left + right) / 2] > target)
                right--;
        }
        return -1;
    }
};