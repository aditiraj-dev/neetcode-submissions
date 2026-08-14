class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(nums, subset, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& subset, int i)
    {
        if(i == nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, subset, i + 1);
        subset.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(nums, subset, i + 1);
    }
};
