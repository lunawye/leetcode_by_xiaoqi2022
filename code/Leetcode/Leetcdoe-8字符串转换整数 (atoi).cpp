class Solution
{
public:
    int myAtoi(string s)
    {
        //去空格
        while (s.length())
        {
            if (s[0] == ' ')
                s = s.substr(1, s.length());
            else
                break;
        }
        //判断正负
        int flag = 1;
        if (s[0] == '-')
        {
            flag = 0;
            s = s.substr(1, s.length());
        }
        else if (s[0] == '+')
            s = s.substr(1, s.length());
        //读入数字
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
                s = s.substr(0, i);
        }
        //去0
        while (s.length())
        {
            if (s[0] == '0')
                s = s.substr(1, s.length());
            else
                break;
        }
        int ans = 0;
        int index = 0;
        if (s.length() > 16)
        {
            if (flag)
                return INT_MAX;
            return INT_MIN;
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++)
        {
            long long temp = ans + (s[i] - '0') * pow(10, index);
            if (temp <= INT_MAX)
            {
                ans = ans + (s[i] - '0') * pow(10, index);
                index++;
            }
            else
            {
                if (flag)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }
        if (!s.length())
            return 0;
        cout << s << endl;
        if (flag)
            return ans;
        return -ans;
    }
};