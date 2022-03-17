class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[left] + nums[right] == target - nums[i] - nums[j])
                    {
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        res.insert(temp);
                        left++;
                    }
                    else if (nums[left] + nums[right] > target - nums[i] - nums[j])
                        right--;
                    else
                        left++;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto i = res.begin(); i != res.end(); i++)
            ans.push_back(*i);
        return ans;
    }
};