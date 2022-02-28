class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int high = prices[prices.size() - 1];
        int sum = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (prices[i] > high)
                high = prices[i];
            if (high - prices[i] > sum)
                sum = high - prices[i];
        }
        return sum;
    }
};