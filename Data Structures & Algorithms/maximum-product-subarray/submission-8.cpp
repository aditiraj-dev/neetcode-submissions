class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = 1, minP = 1;
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = maxP;
            maxP = max(nums[i], max(nums[i]*maxP, nums[i]*minP));
            minP = min(nums[i], min(nums[i]*minP, nums[i]*temp));
            res = max(res, maxP);
        }

        return res;
    }
};
