class Solution {
public:
    int maximumUnits(vector<vector<int>>& vec, int truckSize) {
        sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
        });
        int total=0;
        for(int i=0;i<vec.size();i++){
           if(truckSize-vec[i][0]<0){
               total+=truckSize*vec[i][1];
               truckSize=truckSize-vec[i][0];
               if(truckSize<0){
                 return total;
               }
           }else{
                total+=vec[i][0]*vec[i][1];
                truckSize=truckSize-vec[i][0];
           }
            

        }
        return total;
    }
};