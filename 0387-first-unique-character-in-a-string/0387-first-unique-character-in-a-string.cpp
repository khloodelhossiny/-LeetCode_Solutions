class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>frq(26,0), idx(26, -1);
        for(int i = 0; i < s.size(); i++){
            frq[s[i] - 'a']++;
            if(idx[s[i] - 'a'] == -1){
                idx[s[i] - 'a'] = i;
            }
        }
        vector<int>res;
        for(int i = 0; i < 26; i++){
            if(frq[i] == 1){
                res.push_back(idx[i]);
            }
        }
        sort(res.begin(),res.end());
        if(res.size()){
            return res[0];
        }
        return -1;
    }
};