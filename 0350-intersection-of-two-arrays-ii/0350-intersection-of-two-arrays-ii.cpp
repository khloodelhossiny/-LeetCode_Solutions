class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>frq(10005, 0), res;
        for(int i = 0; i < nums1.size(); i++){
            frq[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++){
            if(frq[nums2[i]] > 0){
                res.push_back(nums2[i]);
                frq[nums2[i]] --;
            }
        }
        return res;
    }
};