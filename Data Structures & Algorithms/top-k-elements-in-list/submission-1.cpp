class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; //numbers to freq

        for(int n : nums) m[n]++;

        unordered_map<int, vector<int>> rev; //freq to numbers

        for(auto& pair : m)
        {
            rev[pair.second].push_back(pair.first);
        }

        vector<int> res;

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
