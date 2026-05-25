class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<bool> chosen(nums.size(), false);
        helper(subset, chosen, nums);

        return res;
    }

    void helper(vector<int>& subset, vector<bool>& chosen, vector<int>& nums)
    {
        if(subset.size() == nums.size())
        {
            res.push_back(subset);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(chosen[i] == true) continue;
            else
            {
                subset.push_back(nums[i]);
                chosen[i] = true;
                helper(subset, chosen, nums);
                subset.pop_back();
                chosen[i] = false;
            }
        }

    }
};
