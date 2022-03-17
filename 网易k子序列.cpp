#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> num;
    vector<int> sum;
    int sum_num = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sum_num += temp;
        num.push_back(temp);
        sum.push_back(sum_num);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(sum[i]);
        for (int j = i + 1; j < n; j++)
        {
            ans.push_back(sum[j] - sum[i]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[k - 1] << endl;
    return 0;
}