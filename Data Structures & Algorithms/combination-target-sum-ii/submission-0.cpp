class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        int i = 0;
        dfs(candidates, target, subset, i);
        return res;
    }

private:
    void dfs(vector<int>& nums, int target, vector<int>& subset, int i)
    {
        if(target == 0)
        {
            res.push_back(subset);
            return;
        }

        if(target < 0  || i >= nums.size()) return;

        subset.push_back(nums[i]);
        dfs(nums, target - nums[i], subset, i + 1);
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        subset.pop_back();
        dfs(nums, target, subset, i + 1);
    }
};
