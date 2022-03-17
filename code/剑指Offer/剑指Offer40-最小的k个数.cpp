class Solution
{
public:
    void quickSort(vector<int> &arr, int left, int right)
    {
        if (left >= right)
            return;
        int compare = arr[left];
        int i = left;
        int j = right;
        while (i < j)
        {
            while (i < j && arr[j] >= compare)
                j--;
            while (i < j && arr[i] <= compare)
                i++;
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[left], arr[i]);
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k > arr.size())
            return arr;
        quickSort(arr, 0, arr.size() - 1);
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(arr[i]);
        return ans;
    }
};