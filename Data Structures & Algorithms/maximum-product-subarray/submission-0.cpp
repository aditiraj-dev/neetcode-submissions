class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            res = max(res, nums[i]);
            int curr = nums[i];
            for(int j = i + 1; j < nums.size(); j++)
            {
                curr *= nums[j];
                res = max(res, curr);
            }
        }

        return res;
    }
};
