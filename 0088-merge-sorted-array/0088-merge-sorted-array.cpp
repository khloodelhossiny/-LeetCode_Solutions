class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        swap(n,m);
        vector<int>v(n + m);
         int l = 0, r = 0, idx = 0;
        while(l < n && r < m){
            if(nums1[l] < nums2[r]){
                v[idx++] = nums1[l++];
            }
            else{
                  v[idx++] = nums2[r++];

            }
        }
        while(l < n){
            v[idx++] = nums1[l++];
        }
        while(r < m){
             v[idx++] = nums2[r++];
        }
        for(int i = 0; i < idx; i++){
            nums1[i] = v[i];
        }
    }
};