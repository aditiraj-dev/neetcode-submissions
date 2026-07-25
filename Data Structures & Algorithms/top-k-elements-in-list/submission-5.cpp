class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> ntofreq;
        for(int n : nums) ntofreq[n]++;
        unordered_map<int, vector<int>> freqton;

        for(auto& pair : ntofreq)
        {
            freqton[pair.second].push_back(pair.first);
        }

        //highest freq a number can have is the size of the array itself

        for(int i = nums.size(); i>=0; i--)
        {
            if(freqton.count(i))
            {
                for(int r : freqton[i])
                {
                    res.push_back(r);
                    if(res.size() == k) return res;
                }
            }
        }

        return {};
    }
};
