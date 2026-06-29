class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        //constraints: less than 20: backtracking
        //op is a list of lists: backtracking
        vector<int> subset;
        helper(subset, nums, 0);
        return res;
    }
    void helper(vector<int>& subset, vector<int>& nums, int i)
    {
        if(i == nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        helper(subset, nums, i + 1);
        subset.pop_back();
        helper(subset, nums, i + 1);
    }
};
