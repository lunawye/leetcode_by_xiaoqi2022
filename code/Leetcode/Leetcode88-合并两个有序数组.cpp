class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans(m + n, 0);
        int index_num1 = 0;
        int index_num2 = 0;
        for (int i = 0; i < m + n; i++)
        {
            if (index_num2 == n)
                ans[i] = nums1[index_num1++]; //要放在前面，不然会越界；
            else if (index_num1 == m)
                ans[i] = nums2[index_num2++];
            else if (index_num1 < m && nums1[index_num1] <= nums2[index_num2])
                ans[i] = nums1[index_num1++];
            else if (index_num2 < n && nums1[index_num1] > nums2[index_num2])
                ans[i] = nums2[index_num2++];
        }
        nums1 = ans;
    }
};