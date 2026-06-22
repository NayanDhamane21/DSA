class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>mp;
        if(nums.size()==1){
            return false;
        }
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int n=nums.size()-1;
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                
                return false;
            }
            if(i==n){
                if(mp[i]!=2){
                    return false;
                }
            }

           
        }
        return true;

    }
};