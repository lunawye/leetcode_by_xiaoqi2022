class Solution
{
public:
    set<vector<int>> res;
    void dfs(vector<int> &nums, int target, int sum, int index)
    {
        sum += nums[index];
        if (index == 4) //保证前面位置回溯完成
        {
            if (nums[0] + nums[1] + nums[2] + nums[3] == target)
            {
                vector<int> temp = {nums[0], nums[1], nums[2], nums[3]};
                sort(temp.begin(), temp.end());
                res.insert(temp);
                return;
            }
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            dfs(nums, target, sum, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};
        dfs(nums, target, 0, 0);
        vector<vector<int>> ans;
        for (auto i = res.begin(); i != res.end(); i++)
            ans.push_back(*i);
        return ans;
    }
};