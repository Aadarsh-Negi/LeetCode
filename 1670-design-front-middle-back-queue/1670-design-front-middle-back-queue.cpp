class FrontMiddleBackQueue {
public:
    vector<int> ar;
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        ar.insert(ar.begin(),val);
    }
    
    void pushMiddle(int val) {
        ar.insert(ar.begin()+ar.size()/2,val);
    }
    
    void pushBack(int val) {
        ar.push_back(val);
    }
    
    int popFront() {
        int val = -1;
        if(ar.size()){
            val = ar[0];
            ar.erase(ar.begin());
        }
        return val;
    }
    
    int popMiddle() {
        int val = -1;
        if(ar.size()){
            val = ar[(ar.size()/2) - (ar.size()%2==0)];
            ar.erase(ar.begin() + ar.size()/2 - (ar.size()%2==0));
        }
        return val;
    }
    
    int popBack() {
        int val = -1;
        if(ar.size()){
            val = ar.back();
            ar.erase(--ar.end());
        }
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */