class Solution {
public:
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums) total += n;
        if(total % 2 != 0) return false;
        int target = total / 2;
        memo.resize(nums.size(), vector<int>(target + 1, -1));
        return helper(0, target, nums);
    }

    bool helper(int i, int target, vector<int>& nums)
    {
        if(target == 0) return true;
        if(i == nums.size() || target < 0) return false;
        if(memo[i][target] != -1) return memo[i][target];

        return memo[i][target] = helper(i+1, target - nums[i], nums) || helper(i+1, target, nums);
    }
};
