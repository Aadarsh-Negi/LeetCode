class Solution {
public:
    double findMedianSortedArrays(vector<int>& x, vector<int>& y) {
        
        
        int n = x.size() + y.size();
        int f = (n-1)/2;
        int s = n/2;
        f+=1;
        s+=1;
        auto find = [&](int v)->int{
            int l = 0;
            int r = (int)x.size()-1;
            int ans = INT_MAX;
            while(l<=r){
                int mid = l + (r-l)/2;
                int fx = upper_bound(y.begin(),y.end(),x[mid]) - y.begin(); // > x[mid] 
                if(fx + mid + 1 >= v){
                    ans = x[mid];
                    r = mid-1;
                }else l = mid+1;
            }  
            return ans; 
        };
        int a = find(f);
        int b = find(s);
        
        swap(x,y);
        
        a = min(a,find(f));
        b = min(b,find(s));
        
        
        double res = a+b;
        res/=2.0;
        return res;  
    }
};