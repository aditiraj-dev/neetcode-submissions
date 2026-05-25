class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]) r--;
            else l++;
        }

        return -1;
    }
};
