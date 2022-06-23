class Solution {
public:
    int scheduleCourse(vector<vector<int>>& ar) {
        priority_queue<int> taken;
        sort(ar.begin(),ar.end(),[&](vector<int> &a,vector<int> &b){
           return a[1]<b[1]; 
        });
        int time=0;
        
        for(int i=0;i<ar.size();i++){
            if(time + ar[i][0] <=ar[i][1]){
                taken.push(ar[i][0]);
                time+=ar[i][0];
            }else{
                if(taken.size() && taken.top() > ar[i][0]){
                    time-=taken.top();
                    taken.pop();
                    time+=ar[i][0];
                    taken.push(ar[i][0]);
                }
            }
        }
        
        
        
        
        return taken.size();
        
    }
};