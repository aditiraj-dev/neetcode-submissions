class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);   
        return helper(nums, 0);
    }

    int helper(vector<int>& nums, int i) //max amount of money you can rob from i
    {
        if(i >= nums.size()) return  0;
        if(memo[i] != -1) return memo[i];

        //two choices: rob current house, skip next house
        //skip current house, go to next house
        memo[i] = max(nums[i] + helper(nums, i + 2), helper(nums, i + 1));
        return memo[i];
        
    }
};
