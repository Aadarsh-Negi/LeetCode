class Solution {
public:
    double findMedianSortedArrays(vector<int>& x, vector<int>& y) {
        
        
        int n = x.size() + y.size();
        int f = (n-1)/2 + 1;
        int s = n/2 + 1;
        
        auto find = [&](int v)->int{
            int l = 0;
            int r = (int)x.size()-1;
            int ans = INT_MAX;
            while(l<=r){
                int mid = l + (r-l)/2;
                
                int fx = 0; 
                int ll = 0;
                int rr = (int)y.size()-1;
                
                while(ll <= rr){
                    int mid2 = ll + (rr-ll)/2;
                    
                    if(y[mid2] <= x[mid]){
                        ll = mid2+1;
                        fx = mid2+1;
                    }else{
                        rr = mid2-1;
                    }
                }
                
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
        
       
        return (a+b) / 2.0;  
    }
};