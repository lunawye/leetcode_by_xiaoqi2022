class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue; //是0跳过
                else if (i == 0)
                    grid[i][j] += grid[i][j - 1]; //如果是第一行，只能从左边进入
                else if (j == 0)
                    grid[i][j] += grid[i - 1][0]; //如果是第一列，只能从上面进入
                else
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); //其他位置，考虑上左两个方向
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1]; //输出最后的答案
    }
};