class Solution {
public:
    vector<vector<int>> cost;
    vector<vector<int>> dp;
    int m, n;

    int recursion(int col, int prev) {

        if (col == n)
            return 0;

        if (dp[col][prev] != -1)
            return dp[col][prev];

        int ans = INT_MAX;

        for (int digit = 0; digit <= 9; digit++) {

            if (digit == prev)
                continue;

            ans = min(ans,
                      cost[col][digit] +
                      recursion(col + 1, digit));
        }

        return dp[col][prev] = ans;
    }

    int minimumOperations(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        cost.assign(n, vector<int>(10, 0));

        // cost[col][digit]
        for (int col = 0; col < n; col++) {

            vector<int> freq(10, 0);

            for (int row = 0; row < m; row++)
                freq[grid[row][col]]++;

            for (int digit = 0; digit <= 9; digit++)
                cost[col][digit] = m - freq[digit];
        }

        dp.assign(n, vector<int>(11, -1));

        return recursion(0, 10);
    }
};