class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for(int r = 0; r < grid.size(); r++)
        {
            for(int c = 0; c < grid[0].size(); c++)
            {
                if(grid[r][c]) //this explores each island
                {
                    int area = 0;
                    dfs(grid, r, c, area); //explore island and calc area of island
                    maxArea = max(maxArea, area); //update maxArea
                }
            }
        }

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int& area)
    {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) return;
        grid[r][c] = 0;
        area++;
        dfs(grid, r+1, c, area);
        dfs(grid, r-1, c, area);
        dfs(grid, r, c+1, area);
        dfs(grid, r, c-1, area);
    }
};
