class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res="",temp="";
        int len=path.length();
        if(path[len-1]!='/'){
            path+="/";
            len++;
        }
        int i=1;
        while(i<len){
            if(path[i]=='/'){
                if(temp==".."){
                    if(!st.empty())
                        st.pop();                    
                }
                else if(temp!="" && temp!="."){
                    st.push(temp);                    
                }
                temp="";
            }else
                temp.push_back(path[i]);
            i++;
        }
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        if(res=="")
            return "/";
        return res;
    }
};