class Solution {
public:
    long long appealSum(string s) {
        long long total=0;
        map<int,int> last;
        for(int i=0; i<s.size();i++){
            total += (s.size()-i)*(s.size()-i+1)/2;
            if(last.count(s[i]))
                total -= (s.size()-i)*(last[s[i]]+1);
            last[s[i]] = i;
        }
        return total;
    }
};