class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            res ^= nums[i];

        }
        for(int i = 0; i <= nums.size(); i++)
        {
            res ^= i;
        }

        return res;
    }
};
