class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqToS;
        vector<vector<string>> res;

        for(int i = 0; i < strs.size(); i++)
        {
            vector<char> freq(26, 0);

            string word = strs[i];

            for(int j = 0; j < word.size(); j++) freq[word[j] - 'a']++;

            string f = to_string(freq[0]);

            for(int j = 1; j < 26; j++)
            {
                f += ',' + to_string(freq[j]);
            }

            freqToS[f].push_back(word);
        }

        for(auto& pair : freqToS)
        {
            res.push_back(pair.second);
        }

        return res;
    }
};
