class Solution {
public:
    map<int,int>mp;

    bool containsDuplicate(vector<int>& nums) {
        for(auto i : nums){
            mp[i]++;
        }
        for(auto i : mp){
            if(i.second > 1){
                return 1;
            }
        }
        return 0;
    }
};