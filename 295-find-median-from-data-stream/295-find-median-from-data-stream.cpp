class MedianFinder {
public:
    priority_queue<int> q1;
    priority_queue<int> q2;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       
        if(q1.size()==0 || num > -q1.top()){
            q1.push(-num);
        }else q2.push(num);
        if(abs((int)q1.size()-(int)q2.size())>1){
            if(q1.size()>q2.size()){
                q2.push(-q1.top());
                q1.pop();
            }else {
                q1.push(-q2.top());
                q2.pop();

            }
        }
        
    }
    
    double findMedian() {
        if(q1.size()==q2.size()){
            int v = -q1.top();
            int v2 = q2.top();
            
            return (v+v2+0.0)/2.0;
        }
       return q1.size() > q2.size() ? -q1.top():q2.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */