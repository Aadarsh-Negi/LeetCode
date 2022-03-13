class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>> ar;
    
    bool book(int start, int end) {
        end--;
        for(auto &it : ar){
            if(it.first<=start && it.second>=start) return 0;
            if(it.first<=end and it.second>=end) return 0;
            if(it.first<=end and it.first>=start) return 0;
            if(it.second>=start and it.second<=end) return 0;
        }
        ar.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */