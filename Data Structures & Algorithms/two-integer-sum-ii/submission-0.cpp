class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //O(1) additional space means we can't use hashset to make loopkup faster
        //however, it is given that the array is sorted
        int l = 0, r = numbers.size() - 1;
        while(l < r)
        {
            int sum = numbers[l] + numbers[r];
            if(sum == target) return {l+1, r+1};
            else if(sum < target) l++;
            else r--;
        }

        return {};
    }
};
