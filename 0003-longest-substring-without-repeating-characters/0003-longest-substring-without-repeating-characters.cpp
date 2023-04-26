class Solution {
public:
    map<char,int>mp;
    
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), c = 0, res = 0;
        while(l<n){
            while(r < n && mp[s[r]] == 0){
                c++;
                mp[s[r++]]++;
            }
            res = max(res, c);          
            mp[s[l]]--;
            if(mp[s[l]] == 0){
                c--;
            }
            l++;
        }
        return res;
    }
};