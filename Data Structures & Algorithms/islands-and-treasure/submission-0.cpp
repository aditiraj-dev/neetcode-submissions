class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0) 
                {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if (r < 0 || r >= grid.size() || c < 0 ||
                    c >= grid[0].size() || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }

    }
};
