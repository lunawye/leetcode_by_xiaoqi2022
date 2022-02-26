class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        if (numbers.size() == 0)
            return -1;
        else if (numbers.size() == 1)
            return numbers[0];
        else if (numbers.size() == 2)
            return min(numbers[0], numbers[1]);
        int left = 0;
        int right = numbers.size() - 1;
        int mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (numbers[mid] < numbers[right]) //此时只可能出现在左半区
            {
                right = mid;
                mid = (left + right) / 2;
            }
            else if (numbers[mid] > numbers[right]) //此时只可能出现在右半区
            {
                left = mid + 1;
            }
            else
                right--; //考虑相等的情况，并不确定
        }
        return numbers[left];
    }
};
