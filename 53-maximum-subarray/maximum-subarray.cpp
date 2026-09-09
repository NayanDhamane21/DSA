class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxi = nums[0];
        int curr = nums[0];

        for (int j = 1; j < nums.size(); j++) {

            if (curr + nums[j] > nums[j]) {
                curr = curr + nums[j];
            }
            else {
                curr = nums[j];
            }

            maxi = max(maxi, curr);
        }

        return maxi;
    }
};