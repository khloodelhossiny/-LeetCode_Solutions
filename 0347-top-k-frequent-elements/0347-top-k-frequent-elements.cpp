class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        map<int, vector<int>>frq;
        vector<int>res;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto i :mp){
            frq[i.second].push_back(i.first);
        }
        for(auto i : frq){
            for(auto j : i.second){
                res.push_back(j);
            }
        }
        k = res.size() - k;
        res.erase(res.begin(),res.begin() + k );

        return res;
    }
};