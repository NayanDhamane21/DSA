class Solution {
public:
    bool vowelOrConsonant(char x)
   {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
        || x == 'u' || x == 'A' || x == 'E' || x == 'I'
        || x == 'O' || x == 'U')
        return true;
    else
        return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(vowelOrConsonant(s[i]) && vowelOrConsonant(s[j])){
                 swap(s[i],s[j]);
                 i++;
                 j--;
                 continue;
            }
            if(!vowelOrConsonant(s[i])){
                i++;
            }
            if(!vowelOrConsonant(s[j])){
                j--;
            }

        }
        return s;
    }
};