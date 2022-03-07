class Solution {
public:
    bool canCross(vector<int>& stones) {
        queue<pair<int,int>> qq;
        unordered_map<int,int> ck;
        for(int &i:stones) ck[i]=1;
        
        if(stones[1]!=1) return 0;
        if(stones.size()==2){
            if(stones[1]!=1) return 0;
            return 1;
        }
        map<pair<int,int>,int> seen;
        qq.push({1,1});
        qq.push({1,2});
        
        while(qq.size()){
            int n=qq.size();
                
                while(n){
                    n--;
                    int i = qq.front().first;
                    int k = qq.front().second;
                    qq.pop();            
                    if(i+k == stones.back()) return 1;
                    if(seen[{i,k}]) continue;
                    seen[{i,k}]=1;
                    if(ck[i+k]){
                        if(k)
                            qq.push({i+k,k});
                        if(k-1>0)
                            qq.push({i+k,k-1});
                        qq.push({i+k,k+1});
                    }
                    
        
                }
            
        }
        return 0;
        
        
    }
};
