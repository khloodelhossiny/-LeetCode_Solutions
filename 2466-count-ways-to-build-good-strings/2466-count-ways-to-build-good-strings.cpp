class Solution {
public:
    long long dp[100005], MOD = 1e9 + 7;
    long long fun(int len, int zero, int one){
        long long &ret = dp[len];
        if(~ret)return ret;
        ret = 0;
        if(len >= one){
            ret += fun(len - one, zero, one);
        }
        if(len >= zero){
            ret += fun(len - zero, zero, one);
        }
        ret %= MOD;
        return ret;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
       long long res = 0;
        for(int i = low; i <= high; i++){
            res += fun(i, zero, one);
            res %= MOD;
        }

        
        return res;
    }
};