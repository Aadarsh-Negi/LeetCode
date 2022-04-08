class KthLargest {
public:
    multiset<int> aa;
    int k;
    KthLargest(int kk, vector<int>& nums) {
        for(int i:nums){
            aa.insert(i);
        }
        k=kk;
        while(aa.size()>k){
            aa.erase(aa.begin());
        }
        
    }
    
    int add(int val) {
        aa.insert(val);
       if(aa.size()>k) aa.erase(aa.begin());
        
        auto vv = aa.begin();
        return *vv;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */