class Solution {
public:
    vector<vector<int>> ans;
    vector<int> used;
    int n2,k2;
    void solve(int k,int n,vector<int> &temp){
        
        if(n==0 && k==0){
            if(temp.size()) {ans.push_back(temp);}
            return;
        }
        if(n<=0 || k<=0) return;
        
        for(int i=1;i<=9;i++){
            if(used[i]) continue;
            temp.push_back(i);
            used[i]=1;
            solve(k-1,n-i,temp);
            temp.pop_back();
            used[i]=0;
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        used.resize(10,0);
        vector<int> a;
        solve(k,n,a);
        set<vector<int>> ss;
        for(vector<int> &s:ans){
            sort(s.begin(),s.end());
            ss.insert(s);
        }
        ans.clear();
        for(vector<int> i:ss) ans.push_back(i);
        
        return ans;
    }
};