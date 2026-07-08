class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> arr;
        for(int i = 0; i < triplets.size(); i++)
        {
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2])
            {
                arr.push_back(triplets[i]);;
            }
        }
        bool one = false, two = false, three = false;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i][0] == target[0]) one = true;
            if(arr[i][1] == target[1]) two = true;
            if(arr[i][2] == target[2]) three = true;
        }
        if(one && two && three) return true;
        return false;
    }
};
