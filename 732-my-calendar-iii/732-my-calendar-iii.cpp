class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int> range;
    
    int book(int start, int end) {
        range[start]++;
        range[end]--;
        int ans=0;
        int pref=0;
        for(auto it:range){
            pref+=it.second;
            ans=max(ans,pref);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */