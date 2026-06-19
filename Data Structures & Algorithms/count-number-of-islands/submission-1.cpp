class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); r++)
        {
            for(int c = 0; c < grid[0].size(); c++)
            {
                if(grid[r][c] == '1')
                {
                    dfs(grid, r, c);
                    res++;
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if(r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || grid[r][c] == '0') return;

        grid[r][c] = '0';

        dfs(grid, r+1, c); //right
        dfs(grid, r-1, c); //left
        dfs(grid, r, c+1); //down
        dfs(grid, r, c-1); //up
    }
};
