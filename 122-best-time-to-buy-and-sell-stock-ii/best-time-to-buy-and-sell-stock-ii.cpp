class Solution {
public:
    int recursion(vector<int>& prices, int i, int buy,vector<vector<int>>&dp) {
        // Base case
        if(i >= prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int include = 0;

        if(buy){
            
            include = recursion(prices, i+1, 0,dp) - prices[i];
        }
        else{
            
            include = prices[i] + recursion(prices, i+1, 1,dp);
        }

        int exclude = recursion(prices, i+1, buy,dp);

        return dp[i][buy]=max(include, exclude);
    }

    int maxProfit(vector<int>& prices) {
    vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return recursion(prices, 0, 1,dp);
    }
};