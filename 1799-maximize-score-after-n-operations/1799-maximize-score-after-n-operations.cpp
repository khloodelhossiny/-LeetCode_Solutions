class Solution {
private:
    int n, vst[15];
    long long dp[(1 << 15) + 5];
    long long gcd(long long a, long long b) { return (a) ? gcd(b % a, a) : b; }
    long long fun(int msk, int c, vector<int>& nums){
       if(__builtin_popcountll(msk) == n){
           return 0;
       }
    long long &ret = dp[msk];
        if(~ret)return ret;
    ret = 0;
    for(int i = 0; i < n;i ++){
        for(int j = i + 1; j < n ;j++){
            if(((msk >> i) & 1) == 0 && (((msk >> j) & 1) == 0)){
                int new_msk = (msk | (1 << i) | (1 << j));
                ret = max(ret, fun(new_msk, c + 1, nums) + ((c + 1) * gcd(nums[i], nums[j])));
            }
        }
    }
    return ret;
    }

public:
    int maxScore(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, nums);
    }
};