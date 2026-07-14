class Solution {
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, 0, 0);
    }

    int helper(string text1, string text2, int i, int j) //returns lcs from respective indices of both strings till end
    {
        if(i == text1.size() || j == text2.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        if(text1[i] == text2[j]) return memo[i][j] = 1 + helper(text1, text2, i + 1, j + 1);

        return memo[i][j] = max(helper(text1, text2, i + 1, j), helper(text1, text2, i, j + 1));
    }
};
