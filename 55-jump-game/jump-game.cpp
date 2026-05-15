class Solution {
public:
    bool recursion(vector<int>& nums, int i, int n, vector<int>& dp) {
        if(i >= n) return false;
        if(i == n - 1) return true;

        if(dp[i] != -1) return dp[i];

        for(int jump = 1; jump <= nums[i]; jump++) {
            if(recursion(nums, i + jump, n, dp)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recursion(nums, 0, nums.size(), dp);
    }
};