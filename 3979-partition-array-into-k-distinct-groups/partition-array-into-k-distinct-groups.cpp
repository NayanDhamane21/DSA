class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

        if (nums.size() % k != 0)
            return false;

        unordered_map<int,int> mp;

        int maxFreq = 0;

        for (int x : nums) {
            mp[x]++;
            maxFreq = max(maxFreq, mp[x]);
        }

        int groups = nums.size() / k;

        return maxFreq <= groups;
    }
};