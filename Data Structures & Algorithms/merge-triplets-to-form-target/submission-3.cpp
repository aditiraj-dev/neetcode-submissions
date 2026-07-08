class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool one = false, two = false, three = false;
        for(int i = 0; i < triplets.size(); i++)
        {
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2])
            {
                if(triplets[i][0] == target[0]) one = true;
                if(triplets[i][1] == target[1]) two = true;
                if(triplets[i][2] == target[2]) three = true;
            }
        }
        if(one && two && three) return true;
        return false;
    }
};
