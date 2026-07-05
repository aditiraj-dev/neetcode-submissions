class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums) total += n;
        if(total %2 != 0) return false;
        int target = total / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
        for(int i = 0; i < nums.size() + 1; i++)
        {
            dp[i][0] = true;
        }

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            for(int t = 1; t <= target; t++)
            {   
                bool take = false;
                if(t - nums[i] >=0) take = dp[i+1][t - nums[i]];
                bool skip = dp[i+1][t];

                dp[i][t] = take || skip;
            }
        }

        return dp[0][target];
    }
    /*
    bool helper(vector<int>& nums, int i, int target)
    {
        if(target == 0) return true;
        if(i >= nums.size()) return false;
        if(target < 0) return false;
        if(memo[i][target] != -1) return memo[i][target];
        memo[i][target] = helper(nums, i + 1, target - nums[i]) || helper(nums, i + 1, target); //either take current element or not
        return memo[i][target];

    }
    */
};
