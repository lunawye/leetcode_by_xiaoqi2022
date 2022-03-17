class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < nums.size())
        {
            if (nums[right] == 0)
                k--;
            right++;
            if (k < 0)
            {
                if (nums[left] == 0)
                    k++;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};