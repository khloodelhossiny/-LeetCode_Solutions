class Solution {
public:
     int dp[50005],n;
    int fun(int i, vector<int>& stoneValue){
        if(i >= n){
            return 0;
        }
        int &ret = dp[i];
        if(~ ret)return ret;
        ret = -1e5;
        for(int x = 1; x <= 3; x++){
            if(i + x - 1 < n){
                int sum = 0;
                for(int j = 0; j < x; j ++){
                    sum += stoneValue[i + j];
                }
                ret = max(ret, sum - fun(i + x, stoneValue));
            }
        }
        return ret;
    }
    string stoneGameIII(vector<int>& stoneValue) {
         n = stoneValue.size();
        memset(dp, -1, sizeof(dp));
        int Alice = fun(0, stoneValue);
        if(Alice > 0){
            return "Alice";
        }
        if(Alice < 0){
            return "Bob";
        }
        return "Tie";
    }
};