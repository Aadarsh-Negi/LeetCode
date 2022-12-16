class MyQueue {
public:
    stack<int> a;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        stack<int> b;
        while(a.size()) b.push(a.top()),a.pop();
        int t  = b.top(); b.pop();
        while(b.size()) a.push(b.top()),b.pop();
        return t;
    }
    
    int peek() {
        stack<int> b;
        while(a.size()) b.push(a.top()),a.pop();
        int t  = b.top();
        while(b.size()) a.push(b.top()),b.pop();
        return t;
    }
    
    bool empty() {
        return a.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */