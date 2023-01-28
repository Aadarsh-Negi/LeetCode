class Solution {
public:
    
    void dist(vector<int> &edges,int s,vector<int> &d1){
        int dx=0;
        while(s>-1 && d1[s]==-1){
            d1[s] = dx++;
            s=edges[s];
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n,-1);
        vector<int> d2(n,-1);
        
        dist(edges,node1,d1);
        dist(edges,node2,d2);
        
        // for(int i:d1) cout<<i<<" ";cout<<"\n";
        // for(int i:d2) cout<<i<<" ";cout<<"\n";
        
        int ans = INT_MAX;
        int idx = -1;
        
        for(int i=0;i<n;i++){
            if(d1[i]!=-1 && d2[i]!=-1){
                int v = max(d1[i],d2[i]);
                if(ans > v) {ans = v; idx = i;}
            }
        }
        return idx;
        
    }
};