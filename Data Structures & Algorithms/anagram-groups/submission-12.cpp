class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ag;
        vector<vector<string>> res;

        for(string str : strs)
        {
            vector<int> freq(26, 0);
            for(char c : str) freq[c - 'a']++;

            string f = to_string(freq[0]);
            for(int i = 1; i < 26; i++) f += ',' + to_string(freq[i]);

            ag[f].push_back(str);
        }

        for(auto& pair : ag)
        {
            res.push_back(pair.second);
        }

        return res;
    }
};


