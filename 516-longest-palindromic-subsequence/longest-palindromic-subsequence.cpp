class Solution {
public:
    int recursion(string &s,string &rev,int i,int j,vector<vector<int>>&dp){
        //basecase
        if(i>=s.length() || j>=rev.length()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        //logic
        int include=0;
        if(s[i]==rev[j]){
            include=1+recursion(s,rev,i+1,j+1,dp);
        }
        int exclude=max(recursion(s,rev,i+1,j,dp),recursion(s,rev,i,j+1,dp));
        


        //return 
        return dp[i][j]=max(include,exclude);
    }
    int longestPalindromeSubseq(string s) {
        string rev="";
        for(int i=s.length()-1;i>=0;i--){
            rev+=s[i];
        }
        vector<vector<int>>dp(s.length(),vector<int>(rev.length(),-1));
        return recursion(s,rev,0,0,dp);
    }
};