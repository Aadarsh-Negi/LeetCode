class Trie {
public:
    int end;
    Trie *ar[300];
    Trie() {
        end=0;
        for(int i=0;i<300;i++) this->ar[i]=NULL;
    }
    
    void insert(vector<int> &word) {
        Trie *cur = this;
        int cnt=1;
        for(int &c:word){
            c = c+100;
            if(!cur->ar[c]) cur->ar[c] = new Trie;
            cur = cur->ar[c];
            if(cnt==word.size()) cur->end=1;
            cnt++;
        }
    }
    
    bool search(vector<int>& word) {
        Trie * cur =this;
        int cnt=1;
        for(int c:word){
            c = c+100;
            if(cur->ar[c])
                cur = cur->ar[c];
            else return 0;
            if(cnt==word.size() && cur->end) {cur->end=0; return 1;}
            cnt++;
        }
        return 0;
    }
};
class Solution {
public:
   
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> ans;
        Trie *tx = new Trie();
        
        for(int i=1;i<(1<<nums.size());i++){
            
            vector<int> temp;
            
            for(int j=0;j<nums.size();j++)
                if((1<<j)&i) 
                    temp.push_back(nums[j]);           
            if(temp.size()>1 && is_sorted(temp.begin(),temp.end()))
                tx->insert(temp);  
        }
        
        for(int i=1;i<(1<<nums.size());i++){
            vector<int> temp;
            
            for(int j=0;j<nums.size();j++)
                if((1<<j)&i) 
                    temp.push_back(nums[j]);           
            
            if(tx->search(temp)) ans.push_back(temp);
        }
        
        return ans;
    }
};