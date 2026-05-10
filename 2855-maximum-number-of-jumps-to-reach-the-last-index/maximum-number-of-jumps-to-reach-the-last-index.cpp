class Solution {
public:
    int recursion(vector<int>& nums, int target, vector<vector<int>>& dp, int i, int j) {
        // Base case
        if (i == nums.size() - 1) {
            return 0;
        }

        if (j >= nums.size()) {
            return -1;
        }

      
        if (dp[i][j] != -2) {
            return dp[i][j];
        }

        // Logic
        int include = -1;

        
        if (abs(nums[j] - nums[i]) <= target) {
            int next = recursion(nums, target, dp, j, j + 1);

            if (next != -1) {
                include = 1 + next;
            }
        }

        
        int exclude = recursion(nums, target, dp, i, j + 1);

        //  return
        return dp[i][j] = max(include, exclude);
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        
        vector<vector<int>> dp(n, vector<int>(n, -2));

        return recursion(nums, target, dp, 0, 1);
    }
};