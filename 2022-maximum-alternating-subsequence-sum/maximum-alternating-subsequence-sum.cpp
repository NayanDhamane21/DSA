class Solution {
public:
    long long recursion(vector<int>& nums, int i, int j,
                        vector<vector<long long>>& dp) {

        // Base case
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Include
        long long include;
        if (j  == 0) {
            include = nums[i] + recursion(nums, i + 1,1 , dp);
        } else {
            include = -nums[i] + recursion(nums, i + 1,0, dp);
        }

        // Exclude
        long long exclude = recursion(nums, i + 1, j, dp);

        // Return
        return dp[i][j] = max(include, exclude);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<long long>> dp(n + 1,vector<long long>(2, -1));

        return recursion(nums, 0, 0, dp);
    }
};