class Solution {
public:
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int n : nums)
        {
            totalSum += n;
        }

        if(totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        memo.resize(nums.size(), vector<int>(target + 1, -1));
        return helper(nums, target, 0, 0);
    }

    bool helper(vector<int>& nums, int target, int currSum, int i)
    {
        if(i == nums.size()) return false;
        if(currSum == target) return true;
        if(currSum > target) return false;
        if (memo[i][currSum] != -1) return memo[i][currSum];
        
        bool ans = helper(nums, target, currSum, i + 1) || helper(nums, target, currSum + nums[i], i + 1);
        memo[i][currSum] = ans;
        return ans;
    }
};
