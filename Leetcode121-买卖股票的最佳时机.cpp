class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int best = 0;
        int high = prices[prices.size() - 1];
        vector<int> dp(prices.size());
        dp[prices.size() - 1] = 0;
        for (int i = prices.size() - 1; i > 0; i--)
        {
            if (prices[i] > high)
                high = prices[i];
            dp[i] = max(high - prices[i - 1], dp[i]);
            if (dp[i] > best)
                best = dp[i];
        }
        return best;
    }
};