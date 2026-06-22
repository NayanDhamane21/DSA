class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,int> firstPos;

        vector<pair<int,char>> v;
        string ans="";

        for(int i=0;i<s.size();i++){
            char ch=s[i];

            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                freq[ch]++;

                if(firstPos.find(ch)==firstPos.end())
                    firstPos[ch]=i;
            }
        }

        for(auto &it:freq){
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end(),[&](auto &a,auto &b){
            if(a.first!=b.first)
                return a.first>b.first;      // higher frequency first

            return firstPos[a.second] < firstPos[b.second];
        });

        int j=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){

                ans += v[j].second;

                freq[v[j].second]--;

                if(freq[v[j].second]==0)
                    j++;
            }
            else{
                ans += s[i];
            }
        }

        return ans;
    }
};