class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int count=1;;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i][0]>mini){
                count++;
                mini=nums[i][1];
            }
            mini=min(mini,nums[i][1]);
        }
        return count;
    }
};