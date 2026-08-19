class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1 , 0));
        for(int i = nums.size() - 1; i>=0; i--)
        {
            for(int j = -1; j <= i; j++)
            {
                if(j == -1 || nums[i] > nums[j])
                {
                    dp[i][j+1] = max(
                        1 + dp[i+1][i+1],
                        dp[i+1][j+1]
                    );
                }
                else
                {
                    dp[i][j+1] = dp[i+1][j+1];
                }
            }
        }

        return dp[0][0]; //returns helper(0, -1)
    }
};
