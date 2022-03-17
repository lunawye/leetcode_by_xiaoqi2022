class Solution
{
public:
    vector<int> smallestK(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> new_arr;
        for (int i = 0; i < k; i++)
            new_arr.push_back(arr[i]);
        return new_arr;
    }
};