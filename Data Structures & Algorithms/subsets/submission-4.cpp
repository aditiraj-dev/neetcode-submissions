class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subsets;
        backtracking(nums, subsets, 0);
        return res;
    }

    void backtracking(vector<int>& nums, vector<int>& subset, int i)
    {
        if(i == nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtracking(nums, subset, i + 1);
        subset.pop_back();
        backtracking(nums, subset, i + 1);
    }
};
