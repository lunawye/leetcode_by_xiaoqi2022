class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> ans;
        int l = 1;
        int r = 2;
        int sum = 3;
        while (l < r)
        {
            if (sum == target)
            {
                vector<int> res;
                for (int i = l; i <= r; i++)
                    res.push_back(i);
                ans.push_back(res);
            }
            if (sum >= target)
            {
                sum -= l;
                l++;
            } //就算等于target,l也要左移
            else
            {
                r++;
                sum += r;
            } //l r都是递增
        }
        return ans;
    }
};
