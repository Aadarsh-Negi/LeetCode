class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> cnt;
        for(int i:tasks) cnt[i]++;
        
        int days=0;
        for(auto it:cnt){
            if(it.second==1) return -1;
            days+=min(it.second/3 + (it.second%3>=1),it.second/2);                 
        }
        
        return days;
        
    }
};