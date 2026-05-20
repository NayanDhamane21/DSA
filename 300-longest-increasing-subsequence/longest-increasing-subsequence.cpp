class Solution {
public:
    int recursion(vector<int>&nums,int prev,int curr,vector<vector<int>>&dp){
        if(curr>=nums.size()) return 0;
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
        int include=0;
        if(prev==-1 || nums[prev]<nums[curr]){
            include=1+recursion(nums,curr,curr+1,dp);
        }
        int exclude=recursion(nums,prev,curr+1,dp);
        return dp[prev+1][curr]=max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        return recursion(nums,-1,0,dp);
    }
};