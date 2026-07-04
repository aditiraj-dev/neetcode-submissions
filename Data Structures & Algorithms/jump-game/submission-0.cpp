class Solution {
public:
    bool canJump(vector<int>& nums) {
        return helper(nums, 0);
    }

    bool helper(vector<int>& nums, int i)
    {
        if(i >= nums.size() - 1) return true;

        int x = nums[i];
        while(x)
        {
            if(helper(nums, i + x)) return true;
            x--;
        }

        return false;
    }
};
