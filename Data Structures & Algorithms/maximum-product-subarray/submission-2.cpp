class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1, curMin = 1;

        for(int n : nums)
        {
            int temp = curMax*n;
            curMax = max(max(curMax*n, curMin*n), n);
            curMin = min(min(temp, curMin*n), n);

            res = max(res, curMax);
        }

        return res;
    }
};
