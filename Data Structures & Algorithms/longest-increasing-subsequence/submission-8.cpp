class Solution {
public:
    vector<vector<int>> memo;
    int lengthOfLIS(vector<int>& nums) {
        //constraints: greedy, dp, heap, hashmap, 2p
        //by op and keywords: we get dp
        memo.resize(nums.size(), vector<int>(nums.size() + 1, -1)); 
        return helper(nums, 0, -1); //returns length longest inc subseq from i till end, on the basis of what was chosen before shown by j
    }

    int helper(vector<int>& nums, int i, int j)
    {
        if(i == nums.size()) return 0; //no subseq can be formed
        if(memo[i][j+1] !=-1) return memo[i][j+1];
        int res = 0;
        if(j == -1 || nums[i] > nums[j]) res = 1 + helper(nums, i + 1, i); //choose i to be in seq
        memo[i][j+1] = max(res, helper(nums, i + 1, j)); //skip i from sequence
        return memo[i][j+1];

    }
};
