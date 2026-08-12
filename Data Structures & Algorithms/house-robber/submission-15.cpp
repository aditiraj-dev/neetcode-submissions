class Solution {
public:
    vector<vector<int>> memo;
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), vector<int>(nums.size() + 1, -1));
        return helper(nums, 0, -1);
    }

    int helper(vector<int>& nums, int i, int prev) //returns max amount of money that can be robbed from i till end
    {
        if(i == nums.size()) return 0;
        if(memo[i][prev+1] != -1) return memo[i][prev+1];

        //you have two choices: rob current house (given prev house was not robbed) or skip this house (last)
        int res = 0;
        if(prev == -1 || prev != i - 1) res += nums[i] + helper(nums, i + 1, i); //rob house
        res = max(res, helper(nums, i + 1, prev)); //skip house

        return memo[i][prev+1] = res;
    }
};
