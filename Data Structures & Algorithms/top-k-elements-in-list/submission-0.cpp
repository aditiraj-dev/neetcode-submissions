class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for(int n : nums)
        {
            count[n] = count[n] + 1;
        }

        for(const auto& entry : count)
        {
            freq[entry.second].push_back(entry.first); //maps freq to number
        }
        
        vector<int> res;

        for(int i = freq.size() - 1; i > 0; i--)
        {
            for(int n : freq[i])
            {
                res.push_back(n);
                if(res.size() == k) return res;
            }
        }

        return res;
    }
};
