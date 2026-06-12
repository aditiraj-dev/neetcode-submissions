class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string s : strs)
        {
            vector<int> freq(26, 0);

            for(char c : s)
            {
                freq[c - 'a']++;
            }

            string f = to_string(freq[0]);
            for(int i = 1; i < 26; i++) f += ',' + to_string(freq[i]);

            m[f].push_back(s);
        }

        vector<vector<string>> res;
        for(auto& pair : m)
        {
            res.push_back(pair.second);
        }

        return res;
    }
};
