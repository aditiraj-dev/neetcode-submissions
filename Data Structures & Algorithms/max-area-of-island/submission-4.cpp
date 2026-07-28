class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j]) 
                {
                    int area = helper(grid, i, j);
                    res = max(res, area);
                }
            }
        }

        return res;
    }

    int helper(vector<vector<int>>& grid, int i, int j) //helper returns area
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        return 1 +
            helper(grid, i - 1, j) + helper(grid, i + 1, j) + helper(grid, i, j - 1) + helper(grid, i, j + 1);

    }
};
