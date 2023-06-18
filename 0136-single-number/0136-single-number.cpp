class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 1 1 2 2 4
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] != nums[i]){
                return nums[i - 1];
            }
            else{
                i++;
            }
        }
        return nums.back();
    }
};