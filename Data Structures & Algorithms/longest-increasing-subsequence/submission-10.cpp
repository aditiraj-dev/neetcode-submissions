class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 2, 0));

        for(int i = nums.size() - 1; i>=0; i--)
        {
            for(int j = i; j >= -1; j--)
            {
                int res = dp[i+1][j+1];

                if(j == -1 || nums[j] < nums[i])
                {
                    res = max(res, 1 + dp[i+1][i+1]);
                }

                dp[i][j+1] = res;
            }
        }

        return dp[0][0];
    }

};
