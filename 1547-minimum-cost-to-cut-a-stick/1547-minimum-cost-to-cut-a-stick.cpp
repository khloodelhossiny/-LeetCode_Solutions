class Solution {
public :
    int dp[105][105];
    int fun(int left, int right, vector<int>& cuts){
    if((right - left) == 1){
        return 0;
    }
    int & ret = dp[left][right];
    if(~ret)return ret;
     ret = 1e9;
    for(int i = left; i < right; i++){
        ret = min(ret, fun(left, i,cuts) + fun(i, right,cuts) + cuts[right] -cuts[left]);
    }
        return ret;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1, sizeof(dp));
        return fun(0, cuts.size() - 1,cuts);
    }
};