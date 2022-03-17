class Solution
{
public:
    vector<double> cards;
    bool helper(vector<double> cards)
    {
        int N = cards.size(); //以数组长度作为终止条件
        if (N == 1 && abs(cards[0] - 24) > 10e-6)
            return false; //不等于24返回false
        if (N == 1 && abs(cards[0] - 24) < 10e-6)
            return true; //等于24返回true
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    continue;
                double a = cards[i]; //取两个数进行加减乘除
                double b = cards[j];
                vector<double> newcards;
                for (int k = 0; k < N; k++)
                {
                    if (k == i || k == j)
                        continue;
                    newcards.push_back(cards[k]); //将未使用的数字存起来
                }
                double sum = a + b;
                double sub = a - b; //将加减乘除得到的数字再进行处理，最终判断是不是等于24
                double mul = a * b;
                double div = a / b;
                vector<double> newcard = {sum, sub, mul, div};
                for (int n = 0; n < 4; n++)
                {
                    newcards.push_back(newcard[n]); //是就返回true
                    if (helper(newcards))
                        return true;
                    newcards.pop_back(); //不是就推出
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int> &_cards)
    {
        for (int i = 0; i < _cards.size(); i++)
        {
            cards.push_back(_cards[i] * 1.0);
        }
        return helper(cards);
    }
};