class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        char c;
        for(auto it:s){
            mp[it]++;
        }
        for(int i=0;i<t.length();i++){
            if(mp[t[i]]>0){
                mp[t[i]]--; 
            }else{
               return t[i];
            }
            
        }
        return c;


    }
};