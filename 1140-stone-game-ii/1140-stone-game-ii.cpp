class Solution {
public:
    int dp[105][1005], suffx[105],n;
    int fun(int i, int m){
        if(i >= n){
            return 0;
        }
        if( i + 2 * m >= n){
            return suffx[i];
        }
        int &ret = dp[i][m];
        if(~ ret)return ret;
        ret = 0;
        for(int x = 1; x <= 2 * m; x++){
            ret = max(ret, suffx[i] - fun(i + x, max(x, m)));
        }
        return ret;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();memset(dp, -1, sizeof(dp));
        suffx[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffx[i] = suffx[i + 1] + piles[i];
        }
        return fun(0, 1);
    }
};