class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + m) % (i);
        }
        return dp[n];
    }
};
//如果知道了f(n-1,m)的解，那么f(n,m)的解就是f(n-1,m)移动m位置的值
//所以f(n,m)的解为 (f(n-1,m)+m)%n 以此类推