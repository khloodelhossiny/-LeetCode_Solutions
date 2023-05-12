class Solution {
public: 
    long long dp[100005], n;
    long long solve(int i, vector<vector<int>>& questions) {
        if(i >= n){
            return 0;
        }
        long long &ret = dp[i];
        if(~ret)return ret;
        return ret = max(solve(i + 1, questions), solve(i + questions[i][1] + 1, questions) + questions[i][0]);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, questions);
    }
};