class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int a = n % 3;
        int times = n / 3;
        int sum = 1;
        for (int i = 0; i < times; i++)
            sum *= 3;
        if (a == 0)
            return sum;
        else if (a == 1)
            return sum / 3 * 4;
        return sum * 2;
    }
};