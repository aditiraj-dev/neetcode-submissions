class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums) total += n;
        if(total %2 != 0) return false;
        int target = total / 2;

        set<int> dp;
        dp.insert(0);

        for(int n : nums)
        {
            set<int> newDp;
            for(int t : dp)
            {
                newDp.insert(t);
                newDp.insert(t + n);
            }
            if(newDp.count(target)) return true;
            dp = newDp;
        }

        return false;
    }
};
