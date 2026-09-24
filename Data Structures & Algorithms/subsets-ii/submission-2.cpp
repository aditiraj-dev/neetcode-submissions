class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(nums, subset, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int> subset, int i)
    {
        if(i == nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, subset, i + 1);
        subset.pop_back();
        int j = i;
        while(j < (nums.size() - 1) && nums[j] == nums[j+1]) j++;
        backtrack(nums, subset, j + 1);
    }
};
