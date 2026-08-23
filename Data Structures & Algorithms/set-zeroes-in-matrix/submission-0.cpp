class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroes;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0) zeroes.push_back({i, j});
            }
        }

        for(auto zero : zeroes)
        {
            //make row zero
            int r = zero.first;
            for(int j = 0; j < matrix[0].size(); j++)
            {
                matrix[r][j] = 0;
            }

            //make col zero
            int c = zero.second;
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][c] = 0;
            }
        }
    }
};
