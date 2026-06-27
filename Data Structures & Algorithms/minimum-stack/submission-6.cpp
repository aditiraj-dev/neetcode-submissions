class MinStack {
public:
    MinStack() {
        
    }
    stack<int> s1; //stack for the standard operations
    stack<int> s2; //stack for the keeping track of minimums
    
    void push(int val) {
        s1.push(val);
        if(!s2.empty() && val > s2.top())
        {
            val = s2.top();
        }
        s2.push(val); //so it pushes the minimum value at this point
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
