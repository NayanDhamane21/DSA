class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string ans="";
         sort(strs.begin(),strs.end());
         int i=0;
         int j=0;
         while(i<strs[0].length() && j<strs[strs.size()-1].length()){
            if(strs[0][i]==strs[strs.size()-1][j]){
                ans+=strs[0][i];
                
            }else{
                break;
            }
            i++;
            j++;
         }
         return ans;
         
    }
};