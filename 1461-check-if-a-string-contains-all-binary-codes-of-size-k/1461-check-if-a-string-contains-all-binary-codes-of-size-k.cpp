class Solution {
public:
    long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
    bool hasAllCodes(string s, int k) {
        set<int> cnt;
        
        string temp;
        for(char &c:s){
            temp+=c;
            if(temp.size()>=k){
                cnt.insert(compute_hash(temp));
                temp.erase(temp.begin());
            }
        }
      
        return cnt.size() == (1<<k);
        
    }
};