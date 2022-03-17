class Solution
{
public:
    vector<string> add;
    void multi(string num, char a, int i, int index)
    {
        if (a == '0')
        {
            return;
        }
        reverse(num.begin(), num.end());
        int ans = 0;
        int x = a - '0';
        string res = "";
        for (int i = 0; i < num.length(); i++)
        {
            int y = num[i] - '0';
            int temp = x * y + ans;
            res += temp % 10 + '0';
            ans = temp / 10;
        }
        if (ans != 0)
            res += ans + '0';
        reverse(res.begin(), res.end());
        for (int j = 0; j < i; j++)
            res += "0";
        add.push_back(res);
    }
    string addStr(string a, string b)
    {
        if (a.length() == 0)
            return b;
        if (b.length() == 0)
            return a;
        string res = "";
        int index_a = 0;
        int index_b = 0;
        int ans = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < (max(a.length(), b.length())); i++)
        {
            int ans_a = 0;
            int ans_b = 0;
            if (i < a.length())
                ans_a += a[i] - '0';
            if (i < b.length())
                ans_b += b[i] - '0';
            ans = ans + ans_a + ans_b;
            res += ans % 10 + '0';
            ans = ans / 10;
        }
        if (ans != 0)
            res += ans + '0';
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply(string num1, string num2)
    {
        if (num1.length() == 0)
            return num2;
        else if (num2.length() == 0)
            return num1;
        if (num1 == "0" || num2 == "0")
            return "0";
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num2.length(); i++)
            multi(num1, num2[i], i, num2.length());
        if (add.size() == 1)
            return add[0];
        string ans = "";
        for (int i = 0; i < add.size(); i++)
            ans = addStr(ans, add[i]);
        return ans;
    }
};