class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curMax = 0;

        for(int n : nums)
        {
            curMax = max(curMax + n, n);
            res = max(res, curMax);
        }

        return res;
    }
};
