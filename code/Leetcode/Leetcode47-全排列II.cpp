class Solution
{
public:
    set<vector<int>> res;
    void dfs(vector<int> &nums, int index)
    {
        if (index == nums.size() - 1)
        {
            res.insert(nums);
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            dfs(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        dfs(nums, 0);
        for (auto i = res.begin(); i != res.end(); i++)
            ans.push_back(*i);
        return ans;
    }
};