class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            int digit=nums[i];
            while(digit/10){
                st.push(digit%10);
                digit=digit/10;
            }
            ans.push_back(digit);
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }

        }
        return ans;
    }
};