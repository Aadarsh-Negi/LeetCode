class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) {
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int ans = 0;
        int cur = 0;
        while(i<=j){
            if(tokens[i] <= p){
                p-=tokens[i++];
                cur++;
            }else if(cur){
                cur--;
                p+=tokens[j--];
            }else break;
            ans=max(cur,ans);
        }
        return ans;
    }
};