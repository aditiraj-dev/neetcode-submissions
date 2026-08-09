class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        helper(candidates, target, subset, 0);
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
            if(i > start && nums[i] == nums[i - 1])
    continue;
            if(nums[i] <= target)
            {
                subset.push_back(nums[i]);
                helper(nums, target - nums[i], subset, i + 1);
                subset.pop_back();
            }
        }
    }
};
