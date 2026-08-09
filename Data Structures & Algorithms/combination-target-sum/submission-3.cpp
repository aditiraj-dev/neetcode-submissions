class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        helper(nums, target, subset, 0);
        return res;
    }

    void helper(vector<int>& nums, int target, vector<int>& subset, int start)
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
                helper(nums, target - nums[i], subset, i);
                subset.pop_back();
            }
        }
    }
};
