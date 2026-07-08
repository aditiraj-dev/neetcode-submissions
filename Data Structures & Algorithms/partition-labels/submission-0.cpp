class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> lastIdx;
        for(int i = 0; i < s.size(); i++)
        {
            lastIdx[s[i]] = i;
        }

        for(int i = 0; i < s.size();)
        {
            int start = i;
            int end = lastIdx[s[i]];
            if(start == end)
            {
                res.push_back(end - start + 1);
                i++;
                continue;
            }
            for(int j = start + 1; j <= end; j++)
            {
                if(s[j] != s[i])
                {
                    end = max(end, lastIdx[s[j]]);
                }
            }

            res.push_back(end - start + 1);
            i = end + 1;
        }

        return res;
    }
};
