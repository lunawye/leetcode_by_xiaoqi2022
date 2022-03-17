class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int right = 1;
        int down = 2;
        int left = 3;
        int up = 4;
        int now = 1;
        vector<int> ans;
        vector<vector<int>> compare = {20, (vector<int>(20, 1))};
        int index = 0;
        int sum = matrix.size() * matrix[0].size();
        int right_side = matrix[0].size() - 1;
        int left_side = 0;
        int up_side = 0;
        int down_side = matrix.size() - 1;
        int i = 0;
        int j = 0;
        while (index < sum)
        {
            if (now == right && index < sum)
            {
                i = left_side;
                j = up_side;
                while (j <= right_side && compare[i][j])
                {
                    compare[i][j] = 0;
                    ans.push_back(matrix[i][j]);
                    //cout<<matrix[i][j]<<endl;
                    j++;
                    index++;
                }
                up_side++;
                now = down;
            }
            if (now == down && index < sum)
            {
                i = up_side;
                j = right_side;
                while (i <= down_side && compare[i][j])
                {
                    compare[i][j] = 0;
                    ans.push_back(matrix[i][j]);
                    //cout<<matrix[i][j]<<endl;
                    i++;
                    index++;
                }
                right_side--;
                now = left;
            }
            if (now == left && index < sum)
            {
                i = down_side;
                j = right_side;
                while (j >= left_side && compare[i][j])
                {

                    compare[i][j] = 0;
                    ans.push_back(matrix[i][j]);
                    cout << matrix[i][j] << endl;
                    j--;
                    index++;
                }
                now = up;
                down_side--;
            }
            if (now == up && index < sum)
            {
                i = down_side;
                j = left_side;
                cout << "d " << down_side << " u " << up_side << " l " << left_side << " r " << right_side << endl;
                while (i >= up_side && compare[i][j])
                {
                    compare[i][j] = 0;
                    ans.push_back(matrix[i][j]);
                    cout << matrix[i][j] << endl;
                    i--;
                    index++;
                }
                now = right;
                left_side++;
            }
        }
        return ans;
    }
};