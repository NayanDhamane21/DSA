class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12){
            hour=0;
        }
        double ans=abs(minutes*6-(minutes*0.5)-hour*30);
        if(ans>180){
            return 360-ans;
        }else{
            return ans;
        }
    }
};