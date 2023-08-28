class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        int n = h.size();
        vector<int> idx(n);
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int &a,int &b){
            return pos[a] < pos[b];
        });
        stack<int> st;
        for(int i=0;i<pos.size();i++){
            int id = idx[i];
            if(d[id] == 'L'){
                if(st.size()){
                        while(st.size() && h[st.top()] < h[id]){
                            h[id]--;
                            h[st.top()] = 0;
                            st.pop();
                        }
                        if(st.size()){
                          if(h[st.top()] == h[id]){
                              h[st.top()] = 0;
                              h[id] = 0;
                              st.pop();
                          } 
                          else{
                              h[st.top()]--;
                              h[id] = 0;
                          }
                        } 
                }
            }else
                st.push(id);
        }        
       vector<int> ans;
        for(int i:h) if(i) ans.push_back(i);
        return ans;
    }
};