class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return helper(0, nums);
    }

    int helper(int i, vector<int>& nums) //return max amount of money that can be robbed from i till end
    {
        if(i >= nums.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int rob = nums[i] + helper(i+2, nums);
        int skip = helper(i+1, nums);
        return memo[i] = max(rob, skip);
    }
};
