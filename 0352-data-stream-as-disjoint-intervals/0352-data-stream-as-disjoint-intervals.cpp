class SummaryRanges {
public:
    set<int> cc;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        cc.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        
        auto i = cc.begin();
        while(i!=cc.end()){
            int cur = *i;
            ans.push_back({*i,*i});
            i++;
            while(i!=cc.end() && cur+1 == *i) cur++,ans.back().back() = cur,i++;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */