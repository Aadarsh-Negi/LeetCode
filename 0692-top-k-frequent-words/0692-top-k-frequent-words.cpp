class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> fq;
        for(string &s:words) fq[s]++;
        sort(words.begin(),words.end());
        words.erase(unique(words.begin(),words.end()),words.end());
        sort(words.begin(),words.end(),[&](string const &a,string const &b){
           if(fq[a] == fq[b]) return a < b;
            return fq[a] > fq[b];
        });
        while(words.size()>k) words.pop_back();
        return words;
    }
};