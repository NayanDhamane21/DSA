class Solution {
public:
    string interpret(string command) {
        string ans="";
        int c=0;
        for(int i=0;i<command.length();i++){
            if(command[i]=='G'){
            ans+='G';
        }else {
            while(command[i]!=')'){
                i++;
                c++;
            }
            if(c==1){
                ans+='o';
            }else{
                ans+='a';
                ans+='l';
            }
            c=0;
        }
        }
        
        return ans;
    }
};