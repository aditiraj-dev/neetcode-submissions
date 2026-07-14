class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<>> minHeap; //stores the kth largest elements, top is their min
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n : nums)
        {
            //whatever is in the heap before, might be the kth largest element still
            minHeap.push(n);
            if(minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
