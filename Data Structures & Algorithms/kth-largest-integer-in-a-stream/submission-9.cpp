class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap; //minHeap is supposed to contain the k largest elements seen so far
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n : nums)
        {
            minHeap.push(n); //might or might not be in the k largest elements
            if(minHeap.size() > k) minHeap.pop();
        }

    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
