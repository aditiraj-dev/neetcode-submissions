class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqAtoWord;

        for(int i = 0; i < strs.size(); i++)
        {
            vector<int> freqA(26, 0);
            string word = strs[i];
            for(int j = 0; j<word.length(); j++)
            {
                freqA[word[j] - 'a']++;
            }

            string freq = to_string(freqA[0]);
            for(int j = 1; j< 26; j++)
            {
                freq += ',' + to_string(freqA[j]);
            }

            freqAtoWord[freq].push_back(word);
        }

        vector<vector<string>> result;

        for(auto &pair : freqAtoWord)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};
