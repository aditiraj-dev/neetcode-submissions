class Solution {
public:
    int directions[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        int time = 0;
        while(!q.empty() && fresh)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto node = q.front();
                int row = node.first, col = node.second;
                q.pop();

                for(int i = 0; i < 4; i++)
                {
                    int nr = row + directions[i][0];
                    int nc = col + directions[i][1];

                    if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1)
                    {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
