class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max_nums(nums.size());
        vector<int> min_nums(nums.size());
        max_nums[0]=nums[0];
        min_nums[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            max_nums[i]=max(max_nums[i-1]*nums[i],max(min_nums[i-1]*nums[i],nums[i]));
            //max的来源可能是最小值×当前值(负负得正),也可能是最大值×当前值(正正)
            min_nums[i]=min(min_nums[i-1]*nums[i],min(max_nums[i-1]*nums[i],nums[i]));
            //min的来源可能是最小值×当前值(负正),也可能是最大值×当前值(负正)
        }
        sort(max_nums.begin(),max_nums.end());
        return max_nums[max_nums.size()-1];
    }
};