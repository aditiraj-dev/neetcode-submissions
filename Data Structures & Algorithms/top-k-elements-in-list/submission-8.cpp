class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; //number to freq
        for(int n : nums) freq[n]++;

        unordered_map<int, vector<int>> m; //freq to N

        for(auto& p : freq)
        {
            m[p.second].push_back(p.first);
        }

        vector<int> res;
        for(int i = nums.size(); i >=1; i--)
        {
            if(m.count(i))
            {
                for(int x : m[i])
                {
                    res.push_back(x);
                    if(res.size() == k) return res;
                }
            }
        }

        return res;
    }
};
