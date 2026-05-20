class Solution {
public:

    int recursion(int curr,
                  vector<vector<int>>& jobs,
                  vector<int>& dp) {

        // base case
        if(curr >= jobs.size()) {
            return 0;
        }

        // memoization
        if(dp[curr] != -1) {
            return dp[curr];
        }

        // find next non-overlapping job
        int low = curr + 1;
        int high = jobs.size() - 1;
        int nextIndex = jobs.size();

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(jobs[mid][0] >= jobs[curr][1]) {
                nextIndex = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // include current job
        int include =
            jobs[curr][2] +
            recursion(nextIndex, jobs, dp);

        // exclude current job
        int exclude =
            recursion(curr + 1, jobs, dp);

        return dp[curr] = max(include, exclude);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back(
                {startTime[i], endTime[i], profit[i]}
            );
        }

        // sort by start time
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);

        return recursion(0, jobs, dp);
    }
};