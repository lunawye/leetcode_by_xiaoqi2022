class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            res ^= nums[i]; //剩下两个异或单独的
        int mask = 1;
        while ((mask & res) == 0)
            mask <<= 1; //找到两个不相同数字第一位不相同的位置
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((mask & nums[i]))
                a ^= nums[i]; //相同的数字会分到同一组，不同的两个数也会因为mask分开，不能写等于1，大于0就可以分组了
            else
                b ^= nums[i]; //不同数字之一所处组，相同数字异或为0
        }
        return vector<int>{a, b};
    }
};
