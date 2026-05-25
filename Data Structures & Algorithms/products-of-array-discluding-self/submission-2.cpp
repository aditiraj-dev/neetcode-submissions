class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefProd(n, 1);
        vector<int> suffProd(n, 1);

        for(int i = 1; i < n; i++)
        {
            prefProd[i] = prefProd[i-1]*nums[i-1];
        }

        for(int i = n - 2; i >= 0; i--)
        {
            suffProd[i] = suffProd[i+1]*nums[i+1];
        }

        vector<int> res(n);

        for(int i = 0; i < n; i++)
        {
            res[i] = prefProd[i]*suffProd[i];
        }

        return res;
    }
};
