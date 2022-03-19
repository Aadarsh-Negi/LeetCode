class FreqStack {
public:
    unordered_map<int,int> cnt;
    
    struct trp{
        int cnt;
        int last_index;
        int val;
        trp(int c,int l,int v){cnt=c; last_index=l; val=v;}
        bool operator<(const trp &a)const{
            if (cnt > a.cnt) return true;
            else if (cnt == a.cnt && last_index > a.last_index) return 1;
            return false;
        }
    };
    set<trp> st;
    int ind;
    FreqStack() {
        ind=1;
     
    }
    
    void push(int val) {
        cnt[val]++;
        st.insert(trp(cnt[val],ind,val));
        ind++;
        // for(trp i:st) cout<<i.cnt<<" "<<i.last_index<<" "<<i.val<<"\n";
        // cout<<"\n";
    }
    
    int pop() {
        trp it = *st.begin();
        int vv = it.val;
        cnt[vv]--;
        
        st.erase(st.begin());
        
//         if(fl) return 0;
//         fl=1;
//         for(trp i:st) cout<<i.cnt<<" "<<i.last_index<<" "<<i.val<<"\n";
        
        return vv;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */