class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        
        int ans=INT_MAX;
        
    for(int k=0;k<2;k++){
        
        for(int i=1;i<=6;i++){
            bool ok=1;
            for(int j=0;j<tops.size();j++){
                ok&=(tops[j]==i || bottoms[j]==i);
            }
            if(ok){
                int cnt=0;
                for(int j=0;j<tops.size();j++){
                    cnt+=(tops[j]!=i);
                }
                ans=min(ans,cnt);
            }
        }
        swap(tops,bottoms);
    }   
        ans=ans==INT_MAX?-1:ans;
        return ans;
        
        
        
        
    }
};