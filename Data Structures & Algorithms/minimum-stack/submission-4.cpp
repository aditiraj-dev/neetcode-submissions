class MinStack {
public:
    MinStack() {
        
    }

    stack<int> s1;
    stack<int> s2;
    
    void push(int val) {
        s1.push(val);
        if(!s2.empty()) val = min(s2.top(), val);
        s2.push(val);
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
