class Solution {
public:
    int recursion(vector<int>nums,int target,vector<int>&dp){
        //base case
        if(target==0){
            return 1;
        }
        if(target<0)return 0;
        if(dp[target]!=-1){
            return dp[target];
        }

        //logic
        int ans=0;
        for(int j=0;j<nums.size();j++){
            ans+=recursion(nums,target-nums[j],dp);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return recursion(nums,target,dp);
    }
};