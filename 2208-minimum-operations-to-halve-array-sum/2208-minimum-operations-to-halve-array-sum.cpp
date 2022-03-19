template<class T> using mxpqll = priority_queue<T>;
class Solution {
public:
    int halveArray(vector<int>& nums) {
        mxpqll<double> mx;
        double ttl=0.0;
        for(int i:nums) mx.push(i),ttl+=i;
        
        
        
        int ans=0;
        double cur=ttl/2.0;
        
        while(cur<ttl){
            ans++;
            double tp = mx.top(); mx.pop();
            ttl-=(tp/2.0);
            tp/=2.0;
                mx.push(tp);
        }
        return ans;
        
        
        
        
    }
};