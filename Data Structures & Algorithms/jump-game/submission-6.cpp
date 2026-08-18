class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            for(int j = nums[i]; j >0; j--)
            {
                if(i + j == goal)
                {
                    goal = i;
                    break;
                }
            }
        }

        return goal == 0;
    }
};
