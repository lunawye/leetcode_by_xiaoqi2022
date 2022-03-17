class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right && left > i)
            {
                if (nums[left] + nums[right] == -nums[i])
                {
                    res.insert({nums[i], nums[left], nums[right]});
                    left++;
                }
                else if (nums[left] + nums[right] > -nums[i])
                    right--;
                else
                    left++;
            }
        }
        vector<vector<int>> ans;
        for (auto i = res.begin(); i != res.end(); i++)
            ans.push_back(*i);
        return ans;
    }
};