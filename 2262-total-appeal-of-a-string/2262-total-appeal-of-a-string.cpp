class Solution {
public:
    long long appealSum(string s) {
        long long total=0;
       vector<int> last(27,-1);
        for(int i=0; i<s.size();i++){
            total += (s.size()-i)*(s.size()-i+1)/2;
            if(last[s[i]-'a']!=-1)
                total -= (s.size()-i)*(last[s[i]-'a']+1);
            last[s[i]-'a'] = i;
        }
        return total;
    }
};