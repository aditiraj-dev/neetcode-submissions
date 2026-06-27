class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //to find number of islands, where islands is a group of connected ones
        //we can use dfs to explore an island by visiting each node
        //to mark an island as visited, we can mark each node as 0
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;

        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
