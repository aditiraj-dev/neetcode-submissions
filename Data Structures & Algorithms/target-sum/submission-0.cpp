class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);
    }

    int helper(vector<int>& nums, int target, int i, int total)
    {
        if(total == target && i == nums.size()) return 1;
        if(i >= nums.size()) return 0;
        int res = 0;

        res += helper(nums, target, i + 1, total + nums[i]) + helper(nums, target, i + 1, total - nums[i]);

        return res;
    }
};
