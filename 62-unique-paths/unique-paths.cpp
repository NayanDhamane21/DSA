class Solution {
public:
    int recursion(int m,int n,vector<vector<int>>&dp){
        if(n==0 && m==0) return 1;
        if(n<0||m<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=recursion(m-1,n,dp)+recursion(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return recursion(m-1,n-1,dp);
    }
};