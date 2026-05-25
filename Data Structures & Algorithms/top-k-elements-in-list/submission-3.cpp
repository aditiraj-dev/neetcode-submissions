class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> f;

        for(int n : nums) f[n]++;

        unordered_map<int, vector<int>> rev;

        for(auto& pair: f)
        {
            rev[pair.second].push_back(pair.first);
        }

        for(int i = nums.size(); i >= 1; i--)
        {
            for(int n : rev[i])
            {
                res.push_back(n);
                k--;
                if(k == 0) return res;
            }
        }

        return res;
    }
};
