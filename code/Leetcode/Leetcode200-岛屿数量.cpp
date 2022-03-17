class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int island)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j, island);
        dfs(grid, i + 1, j, island);
        dfs(grid, i, j - 1, island);
        dfs(grid, i, j + 1, island);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int island = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, island);
                    island++;
                }
            }
        }
        return island;
    }
};