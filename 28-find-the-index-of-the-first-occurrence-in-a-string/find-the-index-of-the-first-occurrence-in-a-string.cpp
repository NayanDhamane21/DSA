class Solution {
public:
    int strStr(string haystack, string needle) {
         int index=-1;
        for(int i=0;i<haystack.size();i++){
            int j=0;
            int k=i;
           
            while(haystack[k]==needle[j]){
                if(j==needle.size()-1){
                    index=i;
                    break;
                }
                j++;
                k++;
            }
            if(index!=-1){
                break;
            }


        }
        return index;
    }
};