class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans="";
        for(auto ch: s){
            if(!st.empty()){
            if(st.size()>1 || ch=='('){
                ans.push_back(ch);
            }
            }
            if(ch=='('){
                st.push(ch);
            }else{
                st.pop();
            }
            
        }
        return ans;
    }
};