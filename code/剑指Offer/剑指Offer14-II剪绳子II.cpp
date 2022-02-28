class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<long long> dp(n + 3);
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        if (n % 3 == 0)
            for (int i = 9; i <= n; i += 3)
                dp[i] = dp[i - 3] * 3 % 1000000007;
        else if (n % 3 == 1)
            for (int i = 7; i <= n; i += 3)
                dp[i] = dp[i - 3] * 3 % 1000000007;
        else
            for (int i = 8; i <= n; i += 3)
                dp[i] = dp[i - 3] * 3 % 1000000007;
        return dp[n];
    }
};