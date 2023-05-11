class Solution {
public:
    int n;
    long long dp[100005][2];
    long long get_max(int i, bool new_sub, vector<int>& nums){
        if(i >= n){
            if(new_sub == 0){
                return -1e5;
            }
            return 0;
        }
        long long &ret = dp[i][new_sub];
        if(~ret) return ret;
        if(new_sub){
            return ret = max(0LL, get_max(i + 1, 1, nums) + nums[i]); 
        }
        ret = max(get_max(i + 1, 0, nums), get_max(i + 1, 1, nums) + nums[i]);
        return ret;
    }
    int maxSubArray(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = nums.size();
        return get_max(0, 0, nums);
    }
};