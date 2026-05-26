class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //use a max heap to store the elements in current window and get their max
        //store both values and indices
        //if index of max doesn't belong to current window, popheap till it does

        priority_queue<pair<int, int>> maxHeap;
        vector<int> res;

        for(int l = 0; l <= nums.size() - k; l++)
        {
            if(maxHeap.empty())
            {
                for(int i = l; i < k; i++) maxHeap.push({nums[i], i});
            }
            else
            {
                maxHeap.push({nums[l + k - 1], l + k - 1});

                while(maxHeap.top().second < l) maxHeap.pop();
            }

            res.push_back(maxHeap.top().first);
        }

        return res;
    }
};
