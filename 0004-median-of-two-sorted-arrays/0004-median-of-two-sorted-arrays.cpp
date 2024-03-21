class Solution {
public:
    double findMedianSortedArrays(vector<int>& x, vector<int>& y) {
        
        
        int n = x.size() + y.size();
        
        int f = (n-1)/2;
        int s = n/2;
        f+=1;
        s+=1;
        // cout<<f<<" <> "<<s<<"\n";
        auto find = [&](int v,vector<int> &x,vector<int> &y)->int{
            int l = 0;
            int r = (int)x.size()-1;
            int ans = INT_MAX;
            while(l<=r){
                int mid = l + (r-l)/2;
                
                int fx = upper_bound(y.begin(),y.end(),x[mid]) - y.begin(); // > x[mid]
                
                if(fx + mid + 1 >= v){
                    // cout<<fx<<" "<<mid<<" ><><>\n";
                    ans = x[mid];
                    r = mid-1;
                }else l = mid+1;
                
            }  
            return ans; 
        };
        double a = min(find(f,x,y),find(f,y,x));
        double b = min(find(s,x,y),find(s,y,x));
       
        
        
        // cout<<a<<" "<<b<<"\n";
        
        a += b;
        a/=2.0;
        return a;  
    }
};