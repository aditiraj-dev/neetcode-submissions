class Solution {
public:
    vector<vector<int>> memo;
    int lengthOfLIS(vector<int>& nums) {
        //to find length of longest strictly increasing subsequence
        //to do this, we need explore all subsequences and take the longest of them all
        //to find a subsequence number by number, we need the previous no selected so we can select next number only greater than it
        //we can explore each subsequence recursively
        memo.resize(nums.size(), vector<int>(nums.size(), -1));
        return helper(nums, 0, -1); //helper returns longest subsequence found from i till the end
    }

    int helper(vector<int>& nums, int i, int j) //i is current number idx, j is previously selected number idx
    {
        if(i == nums.size()) return 0; //no subsequence can be formed if i greater than array size
        if(memo[i][j+1] != -1) return memo[i][j+1];
        int res = 0; //this will be returned at the end as the answer

        //at i, we have two actions: choose it or skip it, depending on what was previously selected
        if(j == -1 || nums[j] < nums[i]) res = 1 + helper(nums, i + 1, i); //chose no at i, and hence it became the j

        //now we also skip it (necessary to explore all other choices)
        memo[i][j+1] = max(res, helper(nums, i + 1, j));

        return memo[i][j+1];
    }
};
