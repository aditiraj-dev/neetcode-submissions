class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!s.count(nums[i] - 1))
            {
                int l = 1;
                while(s.count(nums[i] + l)) l++;
                res = max(res, l);
            }
        }

        return res;
    }
};
