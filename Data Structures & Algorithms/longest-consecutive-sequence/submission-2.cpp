class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res;
        unordered_set<int> s(nums.begin(), nums.end());

        for(int val : s)
        {
            if(s.find(val - 1) == s.end())
            {
                int l = 1;
                while(s.find(val + l) != s.end())
                {
                    l++;
                }

                res = max(res, l);
            }
        }

        return res;
    }
};
