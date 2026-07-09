class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums) total += n;
        if(total %2 != 0) return false;
        int target = total / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));

        for(int i = 0; i < nums.size() + 1; i++) dp[i][0] = true;

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            for(int j = 1; j <= target; j++)
            {
                bool take = false;
                if(j - nums[i] >= 0) take = dp[i+1][j - nums[i]];
                bool keep = dp[i+1][j];

                dp[i][j] = take || keep;
            }
        }

        return dp[0][target];
    }
};
