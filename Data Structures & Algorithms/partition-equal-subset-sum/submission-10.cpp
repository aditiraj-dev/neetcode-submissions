class Solution {
public:
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums) total += n;
        if(total %2 != 0) return false;
        int target = total / 2;
        memo.resize(nums.size(), vector<int>(target + 1, -1));
        return helper(nums, 0, target);
    }

    bool helper(vector<int>& nums, int i, int target)
    {
        if(target == 0) return true;
        if(i == nums.size() || target < 0) return false;
        if(memo[i][target] != -1) return memo[i][target];

        memo[i][target] = helper(nums, i + 1, target) || helper(nums, i + 1, target - nums[i]);
        return memo[i][target];
    }
};
