class Solution {
public:
    unordered_map<int,int>mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;   
        }
         int num2 ;
        for(int i = 0; i < nums.size(); i++){
            num2 = target - nums[i];
            if(mp.find(num2) != mp.end()){
                if(num2 == nums[i]){
                    if(mp[num2] > 1){
                        res[0] = i;
                        break;
                    }
                }
                else{
                    res[0] = i;
                    break;
                }
            }
            
        }
        if(res[0] != -1){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == num2){
                    res[1] = i;
                }
            }
        }
        return res;
        
    }
};