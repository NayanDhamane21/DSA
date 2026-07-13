class Solution {
public:
    int largest(int num){
       int maxi=INT_MIN;
       while(num){
           
           maxi=max(num%10,maxi);
           num=num/10;
       }
       return maxi;
    }
    int smallest(int num){
       int mini=INT_MAX;
       while(num){
           
           mini=min(num%10,mini);
           num=num/10;
       }
       return mini;
    }
    int maxDigitRange(vector<int>& nums) {
        vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            int range=largest(nums[i])-smallest(nums[i]);
            ans.push_back({range,nums[i]});
            
        }
        sort(ans.rbegin(),ans.rend());
        int maxi=ans[0].first;
        int i=0;
        int r=0;
        while(i < ans.size() && ans[i].first==maxi){
            r+=ans[i].second;
            i++;
        }
        return r;
    }
};