class Solution {
public:
vector<vector<int>> dp;
int totalSum;
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        dp.resize(nums.size(), vector<int>(2*totalSum + 1, INT_MIN));
        return helper(nums, target, 0, 0);
    }

    int helper(vector<int>& nums, int target, int i, int total)
    {
        if(total == target && i == nums.size()) return 1;
        if(i == nums.size()) return 0;
        if(dp[i][total + totalSum] != INT_MIN) return dp[i][total + totalSum];
        int res = 0;

        res += helper(nums, target, i + 1, total + nums[i]) + helper(nums, target, i + 1, total - nums[i]);
        dp[i][total + totalSum] = res;
        return res;
    }

};
