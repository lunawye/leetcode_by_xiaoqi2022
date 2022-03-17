class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return false;                                    //如果数组总数过小，不可能划分成功
        int sum = accumulate(nums.begin(), nums.end(), 0);   //计算总和
        int maxNum = *max_element(nums.begin(), nums.end()); //计算最大数值
        int target = sum / 2;                                //计算目标值
        if (sum % 2 == 1 || maxNum > target)
            return false;
        //如果总和为奇数/最大数值大于目标值，不可能符合
        //创建二维数组dp,包含n行,target+1列,其中dp[i][j]表示从数组的[0,i]下标范围内选取若干个正整数(可以是0个),是否存在一种选取方案使得被选取的正整数的和等于j.初始时,dp 中的全部元素都是false.
        //在定义状态之后,需要考虑边界情况。以下两种情况都属于边界情况。
        //如果不选取任何正整数,则被选取的正整数等于0.因此对于所有0<=i<n,都有dp[i][0]=true.
        //当i==0时,只有一个正整数nums[0]可以被选取,因此dp[0][nums[0]]=true。
        vector<vector<int>> dp(n, vector<int>(target + 1, 0)); //i位表示0-i位元素
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                //当j大于等于nums[i]，可以不取nums[i],结果和之前的挂钩nums[i-1][j]
                //可以取nums[i],结果和之前的挂钩nums[i-1][j-nums[i]]
                else
                    dp[i][j] = dp[i - 1][j];
                //如果j小于nums[i]，只能不取，结果和之前挂钩
            }
        }
        return dp[n - 1][target];
    }
};