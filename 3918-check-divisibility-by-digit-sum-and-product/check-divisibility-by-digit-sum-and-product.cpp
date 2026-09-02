class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int multi=1;
        int final=n;
        while(n){
            sum+=n%10;
            multi=multi * (n%10);
            n=n/10;
        }
        int ans=sum+multi;
        return final % ans == 0;
        
        
    }
};