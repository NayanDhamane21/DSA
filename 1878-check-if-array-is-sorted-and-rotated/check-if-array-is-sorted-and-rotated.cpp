class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>s;
        for(int i=0;i<nums.size();i++){
            s.push_back(nums[i]);
        }
        sort(s.begin(),s.end());
        int index=0;
        int curr=nums[0];

        for(int i=1;i<nums.size();i++){
            if(curr>nums[i]){
                index=i;
                curr=nums[i];
            }
            if(curr==nums[i]){
                if(nums[i-1]!=nums[i]){
                    index=i;
                }
            }
        }
        int x=nums.size()-index;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!= s[(i+x) % s.size()]){
                return false;;
            }
        }
        return true;

    }
};