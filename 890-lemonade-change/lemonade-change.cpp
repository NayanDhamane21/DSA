class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int pocket5=0;
        int pocket10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                pocket5=pocket5+5;   
            }else if(bills[i]==10){
                pocket5=pocket5-5;
                pocket10=pocket10+10;

            }else{
                if(pocket10>0){
                   pocket10=pocket10-10;
                }else{
                    pocket5=pocket5-10;
                }
                pocket5=pocket5-5;
                
            }
            if(pocket5<0){
            return false;
        }
        }
        
        return true;
    }
};