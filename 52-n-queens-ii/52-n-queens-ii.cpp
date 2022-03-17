class Solution {
public:
    // int timer=0;
     // set<vector<string>> ans;
    vector<string> bb;
    int ans;
    bool allok(int i,int j,int &n){
        // cout<<timer++<<"\n";
        // for(int k=0;k<bb.size();k++) cout<<bb[i]<<"<\n";
        for(int k=0;k<bb.size();k++){
                if(bb[k][j]=='Q') return 0;
        }
        for(int k=0;k<bb[0].size();k++){
                if(bb[i][k]=='Q') return 0;
        }
        
        for(int k=i-1,k2=j-1;k>=0 && k2>=0;k--,k2--){
            if(bb[k][k2]=='Q') return 0;
        }
        for(int k=i+1,k2=j+1;k<n && k2<n;k++,k2++){
            if(bb[k][k2]=='Q') return 0;
        }
         for(int k=i-1,k2=j+1;k>=0 && k2<n;k--,k2++){
            if(bb[k][k2]=='Q') return 0;
        }
         for(int k=i+1,k2=j-1;k<n && k2>=0;k++,k2--){
            if(bb[k][k2]=='Q') return 0;
        }
       
        return 1;
    }
    void get_all(int &n,int i,int cnt=0){
        if(i>=n){
            if(cnt==n) ans++; 
            // ans.insert(bb);
            
            return;
        }
        
        for(int k=0;k<n;k++){
            if(allok(i,k,n)){
                // cout<<"here\n";
                bb[i][k]='Q';
                get_all(n,i+1,cnt+1);
                bb[i][k]='.';
            }
        }        
    }
    
    
    int totalNQueens(int n) {
        ans=0;
          string ss(n,'.');
        for(int i=0;i<n;i++) bb.push_back(ss);
       
        get_all(n,0);
        return ans;
    }
};