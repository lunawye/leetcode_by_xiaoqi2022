//用map记录字符是否
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() <= 1)
            return s.length();
        map<char, int> res;
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < s.length())
        {
            int temp = 0;
            while (right < s.length() && !res.count(s[right]))
            {
                res[s[right]] = right;
                temp++;
                right++;
            }
            ans = max(temp, ans);
            if (right < s.length())
            {
                left = res[s[right]] + 1;
                right = left;
                res.clear();
            }
        }
        return ans;
    }
};