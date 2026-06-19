class Solution {
public:
    vector<vector<int>> memo;
    int lengthOfLIS(vector<int>& nums) {
        memo = vector<vector<int>>(nums.size(), vector<int>(nums.size() + 1, -1));
        return helper(nums, 0, -1);
    }

    int helper(vector<int>& nums, int i, int j) //returns length of longest s.i subseq from i to the end
    {
        if(i == nums.size()) return 0;
        if(memo[i][j+1] != -1) return memo[i][j+1];
        
        int LIS = helper(nums, i + 1, j);
        if(j == -1 || nums[j] < nums[i])
        {
            LIS = max(LIS, 1 + helper(nums, i + 1, i));
        }
        memo[i][j+1] = LIS;
        return LIS;
    }
};
