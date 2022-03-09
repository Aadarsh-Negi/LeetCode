#define allr(xxx90) xxx90.begin(),xxx90.end(),greater<int>()
#define all(xxx90) xxx90.begin(),xxx90.end()
class Solution {
public:
    
    int val(int &a,vector<int>&mp){
        string s1= to_string(a);
        
        for(char &c:s1){
                // cout<<(c-'0')<<"< ";
                c=mp[c-'0']+'0';
                // cout<<c<<" ";
            }
        return (s1.size()==0?0:stoi(s1));
            
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        
        
        unordered_map<int,int>ind;
        map<int,int> seen;
        int cc=1;
        for(int &i:nums) ind[i]=cc++;
        
        for(int &i:nums) if(seen.count(i)==0) seen[i]=val(i,mapping);
        
        sort(all(nums),[&](const  int &a,const int &b){
    
            int a1 =seen[a];
            int a2 = seen[b];
            
           
            if(a1==a2){
                return ind[a1]<ind[a2];
            }
            return a1<a2;
            
            
            
        });
        
        
        return nums;
        
        
        
    }
};