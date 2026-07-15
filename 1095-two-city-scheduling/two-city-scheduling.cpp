class Solution {
public:
    static bool comparator(vector<int>&a,vector<int>&b){
        return abs(a[1]-a[0])>abs(b[1]-b[0]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
       sort(costs.begin(),costs.end(),comparator);
       int n=costs.size();
       int a=n/2;
       int b=n/2;
       int count=0;
       for(int i=0;i<costs.size();i++){
           if(costs[i][0]<=costs[i][1] && a>0){
               count+=costs[i][0];
               a--;
           }
           else if(costs[i][0]>=costs[i][1] && b>0){
                count+=costs[i][1];
                b--;
           }else{
               if(b>0){
                  count+=costs[i][1];
                  b--;
               }
               if(a>0){
                  count+=costs[i][0];
                  a--;
               }
               
           }
       }
       return count;
    }
};