class Solution
{
public:
    set<string> ans;
    void dfs(string s, int index)
    {
        if (index == s.length() - 1)
            ans.insert(s); //都换了一遍，插入
        for (int i = index; i < s.length(); i++)
        {
            swap(s[i], s[index]); //交换次序，让别的元素填补当前空位
            dfs(s, index + 1);    //下一位，回溯
            swap(s[i], s[index]); //换回来
        }
    }
    vector<string> permutation(string s)
    {
        dfs(s, 0);
        vector<string> res;
        for (auto i = ans.begin(); i != ans.end(); i++)
            res.push_back(*i);
        return res;
    }
};