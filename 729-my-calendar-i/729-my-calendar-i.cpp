class MyCalendar {
public:
    MyCalendar() {
        
    }
    bool cross(pair<int, int>& a, pair<int, int> b){
        return max(a.first, b.first) <= min(a.second, b.second);
    }
    vector<pair<int,int>> ar;
    
    bool book(int start, int end) {
        end--;
        for(auto &it : ar)
            if(cross(it,{start,end})) return 0;
           
        ar.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */