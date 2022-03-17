class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0 || x == INT_MIN)
            return 0;
        int flag = 0;
        if (x > 0)
            flag = 1;
        long long X = abs(x);
        long long ans = 0;
        string res = "";
        while (X > 0)
        {
            ans = ans * 10;
            ans += X % 10;
            X = X / 10;
        }
        if (flag && ans < INT_MAX)
            return ans;
        else if (ans > INT_MAX)
            return 0;
        return -ans;
    }
};