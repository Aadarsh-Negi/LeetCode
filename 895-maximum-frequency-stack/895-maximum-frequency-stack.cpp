class FreqStack {
public:
    unordered_map<int,int> cnt;
    unordered_map<int,stack<int>> st;
    int mx;
    FreqStack(){
        mx=0;
    }
    
    void push(int val) {
        cnt[val]++;
        st[cnt[val]].push(val);
        mx = max(cnt[val],mx);
    }
    
    int pop() {
        int val = st[mx].top();
        st[mx].pop();
        cnt[val]--;
        if(!st[mx].size()) mx--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */