class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a, b, c; a = b = c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                a++;
            }
            else if(nums[i] == 1){
                b++;
            }
        }
        c = nums.size() - a - b;
        int i = 0;
        while(a --){
            nums[i++] = 0;
        }
        while(b--){
            nums[i++] = 1;
        }
        while(c--){
            nums[i++] = 2;
        }
    }
};