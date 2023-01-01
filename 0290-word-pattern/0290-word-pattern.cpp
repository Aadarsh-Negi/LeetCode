class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<string,int> ck;
        unordered_map<char,int> ck2;
        s+=' ';
        
        int ls = 0;
        int j=0;
        while(j<s.size()){
            string temp;
            while(s[j]!=' ') temp+=s[j++];
            j++;
           
            if(ck[temp] == ck2[pattern[ls]]){
                // if(temp != ck2[pattern[ls]]  || pattern[ls]!=ck[temp]) return 0;
                ck[temp]=j+1;
                ck2[pattern[ls++]]=j+1;
                // ls++;
            }
            else 
                return 0;
            //     if(ck.count(temp)){
            //     if(ck[temp]!=pattern[ls++]) return 0;
            // }
        }
        if(ls==pattern.size())
            return 1;
        return 0;
        
        
    }
};