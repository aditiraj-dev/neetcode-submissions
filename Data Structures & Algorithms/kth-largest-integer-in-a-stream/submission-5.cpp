class KthLargest {
public:
    int k = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n : nums)
        {
            minHeap.push(n);
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
