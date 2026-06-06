class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k = 0;
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
        //kth largest integer in a stream of values is the minimum in latest k numbers
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();

        return minHeap.top();
    }
};
