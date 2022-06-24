class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> qq;
        long ss=0;
        for(int &i:target) qq.push(i),ss+=i;
        
        int cnt=0;
        while(qq.size()){
            int tp = qq.top(); qq.pop();
            ss-=tp;
            
            if(ss==1 || tp==1) return 1;
            if(tp<ss || ss==0 || tp%ss == 0) return 0;
            tp%=ss;
            ss+=tp;
            qq.push(tp);
        }
        return 0;
    }
};