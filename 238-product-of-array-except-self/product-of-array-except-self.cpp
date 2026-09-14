class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prev(n);
        vector<int> next(n);
        vector<int> ans(n);

        // Prefix product
        prev[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prev[i] = prev[i - 1] * nums[i];
        }

        // Suffix product
        next[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            next[i] = next[i + 1] * nums[i];
        }

        // Product except self
        ans[0] = next[1];

        for(int i = 1; i < n - 1; i++) {
            ans[i] = prev[i - 1] * next[i + 1];
        }

        ans[n - 1] = prev[n - 2];

        return ans;
    }
};