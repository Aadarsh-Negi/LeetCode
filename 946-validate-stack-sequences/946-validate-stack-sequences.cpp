class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int last=0;
        int i=0;
        
        while(i<pushed.size() && last<popped.size()){
          if(i>=0 && popped[last]==pushed[i]) pushed.erase(pushed.begin()+i),i=max(0,i-1),last++;
          else i++;
            // for(int i:pushed) cout<<i<<" ";cout<<"\n";
            
        }
        return last==popped.size();
    }
};