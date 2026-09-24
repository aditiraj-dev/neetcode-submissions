class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        backtrack(nums, subset, target, 0);
        return res;
    }
    void backtrack(vector<int>& nums, vector<int>& subset, int target, int start)
    {
        if(target == 0)
        {
            res.push_back(subset);
            return;
        }

        for(int i = start; i < nums.size(); i++)
        {
            if(nums[i] <= target)
            {
                subset.push_back(nums[i]);
                backtrack(nums, subset, target - nums[i], i);
                subset.pop_back();
            }
        }
    }
};
