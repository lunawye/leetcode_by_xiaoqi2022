class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (goal.length() != s.length())
            return false;
        string ss = s + s;
        int flag = 0;
        for (int i = 0; i < ss.length(); i++)
        {
            if (ss[i] == goal[0])
            {
                string compare = ss.substr(i, goal.length());
                if (compare == goal)
                    return true;
            }
        }
        return false;
    }
};