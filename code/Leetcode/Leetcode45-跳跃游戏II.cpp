class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int end = 0;                              //上一次跳跃能达到的最远的下标
        int max_index = 0;                        //跳跃能到达的最远的下标
        int step = 0;                             //跳跃的步骤
        for (int i = 0; i < nums.size() - 1; i++) //防止因为落在边界出现，多加了一步
        {
            max_index = max(max_index, i + nums[i]);
            if (i == end)
            {
                end = max_index;
                step++;
            }
        }
        return step;
    }
};