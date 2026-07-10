class Solution {
public:
    vector<vector<int>> memo;
    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        return helper(0, 0, m, n); 
    }

    int helper(int i, int j, int m, int n) //counts number of ways to get to last cell
    {
        if(i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if(i >= m || j >= n) return 0;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        return memo[i][j] = helper(i + 1, j, m, n) + helper(i, j + 1, m, n); 
    }
};
