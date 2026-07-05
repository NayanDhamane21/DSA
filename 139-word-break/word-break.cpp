class Solution {
public:
    bool recursion(string &s, unordered_map<string, int> &mp, int i, int j,vector<vector<int>>&dp) {
        // Base cases
        if (i == s.size())
            return true;

        if (j == s.size())
            return false;
        if(dp[i][j]!=-1) return dp[i][j];
        // Include
        bool include = false;
        if (mp.find(s.substr(i, j - i + 1)) != mp.end()) {
            include = recursion(s, mp, j + 1, j + 1,dp);
        }

        // Exclude
        bool exclude = recursion(s, mp, i, j + 1,dp);

        return dp[i][j]=include || exclude;
    }

    bool wordBreak(string s, vector<string>& w) {
        unordered_map<string, int> mp;

        for (int i = 0; i < w.size(); i++) {
            mp[w[i]]++;
        }
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length(),-1));
        return recursion(s, mp, 0, 0,dp);
    }
};