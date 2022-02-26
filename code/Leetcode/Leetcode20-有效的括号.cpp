class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> res;
        for (int i = 0; i < s.length(); i++)
        {
            if (res.empty())
                res.push(s[i]);
            else if (res.top() == '(' && s[i] == ')')
                res.pop();
            else if (res.top() == '[' && s[i] == ']')
                res.pop();
            else if (res.top() == '{' && s[i] == '}')
                res.pop();
            else
                res.push(s[i]);
        }
        if (res.empty())
            return true;
        return false;
    }
};