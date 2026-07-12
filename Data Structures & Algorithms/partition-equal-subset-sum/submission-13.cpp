class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums) total += n;
        if(total % 2 != 0) return false;
        int target = total / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
        for(int i = 0; i <= nums.size(); i++)
        {
            dp[i][0] = true;
        }

        for(int i = nums.size() - 1; i>=0; i--)
        {
            for(int t = 1; t <= target; t++)
            {
                bool take = false;
                if(t - nums[i] >= 0) take = dp[i+1][t - nums[i]];
                bool keep = dp[i+1][t];

                dp[i][t] = take || keep;
            }
        }

        return dp[0][target];
    }
};
