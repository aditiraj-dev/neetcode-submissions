class Solution {
public:
    int jump(vector<int>& nums) {
        //start from the last index as the goal
        //go back to find the highest nums[i] that can reach this index, this becomes the new goal
        //repeat till you reach index 0
        int res = 0, l = 0, r = 0;
        while(r < nums.size() - 1)
        {
            int farthest = 0;
            for(int i = l; i <=r; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }

        return res;

    }
};
