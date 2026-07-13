class Solution {
public:
    int rob(vector<int>& nums) {
        //vector<int> dp(nums.size() + 2, -1);
        //dp[nums.size()] = 0;
        //dp[nums.size() + 1] = 0;

        int one = 0, two = 0;

        for(int i = nums.size() - 1; i >=0; i--)
        {
            //dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
            int curr = max(nums[i] + two, one);
            two = one;
            one = curr;
        }

        return one;
        
    }
};
