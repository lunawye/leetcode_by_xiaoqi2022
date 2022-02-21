class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int max = num1.length() > num2.length() ? num1.length() : num2.length();
        string num_ans = "";
        int temp = 0;
        for (int i = 0; i < max; i++)
        {
            if (i < num1.size())
                temp += num1[i] - '0';
            if (i < num2.size())
                temp += num2[i] - '0';
            if (temp <= 9)
            {
                num_ans += temp + '0';
                temp = 0;
            }
            else if (temp > 9)
            {
                num_ans += temp % 10 + '0';
                temp = temp / 10;
            }
        }
        if (temp != 0)
            num_ans += temp + '0';
        reverse(num_ans.begin(), num_ans.end());
        return num_ans;
    }
};