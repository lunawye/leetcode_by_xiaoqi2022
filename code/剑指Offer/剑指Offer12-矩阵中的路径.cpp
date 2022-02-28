class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word, int index, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
            return false;
        if (index == word.length() - 1)
            return true;
        bool res;
        board[i][j] = '\0';
        res = dfs(board, word, index + 1, i - 1, j) || dfs(board, word, index + 1, i + 1, j) || dfs(board, word, index + 1, i, j - 1) || dfs(board, word, index + 1, i, j + 1);
        board[i][j] = word[index];
        return res;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> vis(board.size(), vector(board[0].size(), 1));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0])
                    if (dfs(board, word, 0, i, j))
                        return true;
        return false;
    }
};