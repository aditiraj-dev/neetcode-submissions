class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums)
        {
            total += n;
        }

        if(total % 2 != 0) return false;

        return helper(nums, 0, total/2, 0);
    }

    bool helper(vector<int>& nums, int i, int target, int curr)
    {
        if(i >= nums.size()) return false;
        if(curr == target) return true; 
        //two choices at each i: either include it in running sum or exclude it
        return helper(nums, i + 1, target, curr + nums[i]) || helper(nums, i + 1, target, curr);

    }
};
