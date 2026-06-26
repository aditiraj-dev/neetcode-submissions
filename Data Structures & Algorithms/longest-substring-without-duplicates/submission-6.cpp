class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window, dynamic size: as question is asking about a subarray that satisfies a constraint of no duplicates
        int l = 0;
        unordered_set<char> window; //set is used to maintain a window
        int res = 0;

        for(int r = 0; r < s.size(); r++) //create a dynamic window this way since we don't have a window length in this question; subarray can be of any size
        {
            while(window.count(s[r])) //decrease window by incrementing l when it violates the constraint of no duplicate characters
            {
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]); //insert character
            res = max(res, r - l + 1); //update res
        }

        return res;
    }
};
