class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> dpleft(ratings.size(), 0);
        vector<int> dpright(ratings.size(), 0);
        vector<int> dp(ratings.size(), 0);
        for (int i = 0; i < ratings.size(); i++)
        {
            if (i > 0 && ratings[i] > ratings[i - 1])
                dpleft[i] = dpleft[i - 1] + 1;
            else
                dpleft[i] = 1;
            //从0往大小标走，需要和前一个比，确定大小
        }
        for (int i = ratings.size() - 1; i >= 0; i--)
        {
            if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1])
                dpright[i] = dpright[i + 1] + 1;
            else
                dpright[i] = 1;
            //从大下标往0走，需要和后一个比，确定大小
        }
        int sum = 0;
        for (int i = 0; i < ratings.size(); i++)
            dp[i] = max(dpleft[i], dpright[i]);
        for (int i = 0; i < ratings.size(); i++)
            sum += dp[i];
        return sum;
    }
};