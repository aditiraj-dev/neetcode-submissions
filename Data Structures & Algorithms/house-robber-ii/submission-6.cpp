class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> a(nums.begin(), nums.end() - 1);
        vector<int> b(nums.begin() + 1, nums.end());

        memo.assign(a.size(), -1);
        int x = helper(a, 0);

        memo.assign(b.size(), -1);
        int y = helper(b, 0);

        return max(x, y);
    }

    int helper(vector<int>& nums, int i)
    {
        if(i >= nums.size()) return 0;
        if(memo[i] != -1) return memo[i];

        memo[i] = max(helper(nums, i + 1), nums[i] + helper(nums, i + 2));
        return memo[i];
    }
};
