class Solution
{
public:
    char firstUniqChar(string s)
    {
        map<char, int> res;
        for (int i = 0; i < s.length(); i++)
            res[s[i]]++;
        for (int i = 0; i < s.length(); i++)
            if (res[s[i]] == 1)
                return s[i];
        return ' ';
    }
};