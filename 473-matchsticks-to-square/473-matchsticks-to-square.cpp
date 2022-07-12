class Solution {
public:
    
    int ech;
    
    bool solve(vector<int> &ar,int sum,int k,vector<int> &done,int j=0){
        
        if(k==1){
            return 1;
        }
        if(sum==0){
            return solve(ar,ech,k-1,done);
        }
        
        for(int i=j;i<ar.size();i++){
            if(!done[i] && ar[i]<=sum){
                done[i] = 1;
                if(solve(ar,sum - ar[i],k,done,i+1)) return 1;
                done[i] = 0;
            }
        }
        return 0;
        
    }
    bool makesquare(vector<int>& ar) {
        int ss=0;
        for(int &i:ar) ss+=i;
        if(ss%4) return 0;
        
        ech = ss/4;
        
        vector<int> done(ar.size(),0);
        
        return solve(ar,ech,4,done);
        
        // return ans;
     
    }
};