class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> num;    //暂存数字
        stack<string> cha; //暂存字符串
        for (int i = 0; i < s.length(); i++)
        {
            //将数字存到栈中
            if (s[i] >= '1' && s[i] <= '9')
            {
                string temp = "";
                while (i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    temp += s[i];
                    i++;
                }
                int temp_num = stoi(temp);
                num.push(temp_num);
                i--; //回退一步
            }
            //如果出现括号左边，进入字符串判断
            else if (s[i] == '[')
            {
                //将得到字符串存入栈中
                i++;
                string temp = "";
                while (i < s.length() && s[i] >= 'a' && s[i] <= 'z')
                {
                    temp += s[i];
                    i++;
                }
                cha.push(temp);
                i--; //回退一步
            }
            else if (s[i] == ']')
            {
                //如果遇到括号右边，判断要重复几次
                int x = num.top();
                num.pop();
                string str = cha.top();
                cha.pop();
                string res = "";
                while (x--)
                    res += str;
                string y = ""; //加上之前的
                if (!cha.empty())
                {
                    y = cha.top();
                    cha.pop();
                }
                y += res;
                cha.push(y);
            }
            else if (i < s.length() && s[i] >= 'a' && s[i] <= 'z') //如果不用重复
            {
                string y = "";
                if (!cha.empty())
                {
                    y = cha.top();
                    cha.pop();
                }
                y += s[i];
                cha.push(y);
            }
        }
        string res = "";
        res = cha.top();
        return res;
    }
};