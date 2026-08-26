class Solution {
public:
    bool canConstruct(string ran, string magazine) {
       unordered_map<char,int>mp;
       for(int i=0;i<magazine.size();i++){
          mp[magazine[i]]++;
       }
       for(int i=0;i<ran.size();i++){
          if(mp.find(ran[i])!=mp.end() && mp[ran[i]]>0){
              mp[ran[i]]--;
          }else{
             return false;
          }
       }
       return true;
    }
};