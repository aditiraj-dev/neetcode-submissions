class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r)
        {
            int m = (l + r)/2;
            if(nums[m] > nums[r]) //in right sorted portion
            {
                l = m + 1;
            }
            else if(nums[m] < nums[r]) r = m;
        }

        return nums[l];
    }
};
