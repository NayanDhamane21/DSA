class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(curr+nums[i]<nums[i]){
                curr=0;
                curr+=nums[i];
            }else{
                curr+=nums[i];
            }
            maxi=max(curr,maxi);
        }
        return maxi;
    }
};