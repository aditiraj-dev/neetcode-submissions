class MedianFinder {
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int> maxHeap;
public:
    vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.empty() && maxHeap.empty()) minHeap.push(num);
        else if(!minHeap.empty() && num > minHeap.top()) minHeap.push(num);
        else if(!minHeap.empty() && num <= minHeap.top()) maxHeap.push(num);

        if(abs((int)minHeap.size() - (int)maxHeap.size()) > 1)
        {
            if(minHeap.size() > maxHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size())
        {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else if(minHeap.size() > maxHeap.size()) return minHeap.top();
        else return maxHeap.top();
    }
};
