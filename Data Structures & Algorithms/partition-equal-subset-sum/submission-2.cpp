class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //to partition the array into two equal subsets whose sum is the same
        //first calc total sum
        //if even, then continue otherwise return false
        //explore subsets of nums recursively which sum up to half of target
        int total = 0;
        for(int n : nums) total += n;
        if(total %2 !=0) return false;

        return helper(nums, 0, total/2);
    }

    bool helper(vector<int>& nums, int i, int target)
    {
        if(target == 0) return true;
        if(i >= nums.size()) return false;

        return helper(nums, i + 1, target - nums[i]) || helper(nums, i + 1, target);

    }
};
