class Solution {
public:
    int n,m;
    int dp[505][505];
    int get_max(int i, int j,vector<int>& nums1, vector<int>& nums2){
        if(i == n || j == m){
            return 0;
        }
        int &ret = dp[i][j];
        if(~ret) return ret;
       ret = get_max(i, j + 1, nums1, nums2);
        ret = max(ret, get_max(i + 1, j, nums1, nums2));
        if(nums1[i] == nums2[j]){
            ret = max(ret, get_max(i + 1, j + 1, nums1, nums2) + 1);         
        }
        return ret;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        memset(dp, -1, sizeof(dp));
        return get_max(0, 0, nums1, nums2);

    }
};