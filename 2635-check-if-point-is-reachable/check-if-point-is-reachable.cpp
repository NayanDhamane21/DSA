class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int gcd=__gcd(targetX,targetY);
        if((gcd&(gcd-1))==0) return true;
        return false;
    }
};