class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size(); //先获取s的长度
        if (n < 2)
            return s; //如果是单独的一个，必然是回文子串
        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n)); //dp[i][j]表示{i...j}是不是回文串
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;            //所有长度为1的子串都是回文串
        for (int L = 2; L <= n; L++) //从2一直找到最长的回文串
        {
            for (int i = 0; i < n; i++)
            {
                int j = L + i - 1; //获得另一端j的坐标,j的坐标等于长度+i坐标-1
                if (j >= n)
                    break; //如果越界
                if (s[i] != s[j])
                    dp[i][j] = false; //判断条件为dp[i][j]=dp[i-1][j-1]^(dp[i]==dp[j])
                else if (s[i] == s[j] && j - i <= 2)
                    dp[i][j] = true; //如果长度为2或者为3,是回文串
                else
                    dp[i][j] = dp[i + 1][j - 1]; //如果长度大于3,需要加入别的判断

                if (dp[i][j] && L > maxLen)
                {
                    maxLen = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};