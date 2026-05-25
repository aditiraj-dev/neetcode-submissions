class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefProd(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++)
        {
            prefProd[i] = prefProd[i-1]*nums[i-1];
        }

        int postfix = 1;

        for(int i = nums.size() - 1; i >=0; i--)
        {
            prefProd[i] *= postfix;
            postfix *= nums[i];
        }

        return prefProd;
    }
};
