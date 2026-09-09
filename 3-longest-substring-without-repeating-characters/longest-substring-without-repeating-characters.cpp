class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int maxi=0;
        int i=0;
        
        for(int j=0;j<s.length();j++){
            if(mp.find(s[j])!=mp.end() && i<=mp[s[j]]){
                i=mp[s[j]]+1;
            }
            mp[s[j]]=j;
            maxi=max(j-i+1,maxi);
        }
        return maxi;
    }
};